#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#include <iostream>
#include <cstdlib>
#include <list>

// Calcula el n-ésimo número de la secuencia de Jacobsthal
static int jacobsthal(int n) {
  int a = 1, b = 1;
  for (int i = 0; i < n; ++i) {
    int tmp = b;
    b = b + a * 2; // J(i) = J(i-1) + 2 * J(i-2)
    a = tmp;
  }
  return b;
}

template <typename Container> struct GenericElement {
  char kind; // Puede ser, por ejemplo, 'x' o 'y'
  int label;
  Container data;
};

// Función auxiliar para avanzar un iterador de forma segura (compatible con
// C++98)
template <typename Iter> bool safeAdvance(Iter &it, Iter endIt, int steps) {
  while (steps > 0) {
    if (it == endIt)
      return false;
    ++it;
    --steps;
  }
  return true;
}

// Búsqueda binaria en una lista de GenericElement para encontrar la posición de
// inserción. Renombrada a binaryLocate.
template <typename Container>
typename std::list<GenericElement<Container> >::iterator
binaryLocate(std::list<GenericElement<Container> > &primaryList, int value,
             typename std::list<GenericElement<Container> >::iterator boundary) {
  typedef typename std::list<GenericElement<Container> >::iterator IterType;
  IterType start = primaryList.begin();
  IterType mid;
  while (start != boundary) {
    mid = start;
    std::advance(mid, std::distance(start, boundary) / 2);
    if (value < mid->data.back())
      boundary = mid;
    else {
      start = mid;
      if (std::distance(start, boundary) == 1)
        return ++start;
    }
  }
  return start;
}

// Inicializa la lista primaria de fragmentos a partir del contenedor de origen.
// Renombrada a initPrimary.
template <typename Container>
void initPrimary(std::list<GenericElement<Container> > *primaryList,
                 Container *origin, int recursionLevel) {
  GenericElement<Container> element;
  // Se crea un subcontenedor de tamaño 2^(recursionLevel)
  Container subData(1 << recursionLevel);
  // Se posiciona el iterador en la posición 2^(recursionLevel)
  typename Container::iterator it = origin->begin() + (1 << recursionLevel);
  int assignLabel = 1;
  while (it != origin->end()) {
    std::copy(it, it + (1 << recursionLevel), subData.begin());
    element.data = subData;
    element.kind = 'x'; // nuevo nombre para el tipo (antes 'a')
    element.label = assignLabel++;
    primaryList->push_back(element);
    if ((1 << recursionLevel) + (1 << (recursionLevel + 1)) >
        std::distance(it, origin->end()))
      break;
    it += 1 << (recursionLevel + 1);
  }
}

// Inicializa la lista secundaria (pendientes) a partir del contenedor origen.
// Renombrada a initSecondary.
template <typename Container>
GenericElement<Container>
initSecondary(std::list<GenericElement<Container> > *secondaryList,
              Container *origin, int recursionLevel) {
  GenericElement<Container> element;
  Container subData(1 << recursionLevel);
  typename Container::iterator it = origin->begin();
  int assignLabel = 1;
  while (it != origin->end()) {
    std::copy(it, it + (1 << recursionLevel), subData.begin());
    element.data = subData;
    element.kind = 'y'; // antes 'b'
    element.label = assignLabel++;
    secondaryList->push_back(element);
    if ((1 << (recursionLevel + 2)) > std::distance(it, origin->end()))
      break;
    it += 1 << (recursionLevel + 1);
  }
  if ((1 << recursionLevel) + (1 << (recursionLevel + 1)) <=
      std::distance(it, origin->end())) {
    it += 1 << (recursionLevel + 1);
    std::copy(it, it + (1 << recursionLevel), subData.begin());
    element.data = subData;
    element.kind = 'y';
    element.label = assignLabel++;
    return element;
  }
  element.label = 0;
  return element;
}

// Fase de inserción que fusiona los fragmentos ordenados, renombrada a
// mergeInserts.
template <typename Container>
void mergeInserts(Container *origin, int recursionLevel) {
  int jacob_iter = 1;
  std::list<GenericElement<Container> > primaryList;
  std::list<GenericElement<Container> > secondaryList;
  GenericElement<Container> oddElement;

  initPrimary(&primaryList, origin, recursionLevel);
  oddElement = initSecondary(&secondaryList, origin, recursionLevel);

  // Inserta el primer elemento pendiente en la lista primaria.
  primaryList.insert(primaryList.begin(), secondaryList.front());
  secondaryList.pop_front();

  while (!secondaryList.empty()) {
    typename std::list<GenericElement<Container> >::iterator insertIt =
        secondaryList.begin();
    size_t numInsertions = jacobsthal(jacob_iter) - jacobsthal(jacob_iter - 1);
    if (numInsertions > secondaryList.size())
      numInsertions = secondaryList.size();
    std::advance(insertIt, numInsertions - 1);
    for (; numInsertions > 0; numInsertions--) {
      typename std::list<GenericElement<Container> >::iterator boundary =
          primaryList.begin();
      while (boundary->label != insertIt->label)
        ++boundary;
      typename std::list<GenericElement<Container> >::iterator slot =
          binaryLocate<Container>(primaryList, insertIt->data.back(), boundary);
      primaryList.insert(slot, *insertIt);
      typename std::list<GenericElement<Container> >::iterator tmp = insertIt;
      --tmp;
      secondaryList.erase(insertIt);
      insertIt = tmp;
    }
    jacob_iter++;
  }
  if (oddElement.label != 0) {
    typename std::list<GenericElement<Container> >::iterator slot =
        binaryLocate<Container>(primaryList, oddElement.data.back(),
                                primaryList.end());
    primaryList.insert(slot, oddElement);
  }
  Container newContainer;
  typename std::list<GenericElement<Container> >::iterator itList =
      primaryList.begin();
  for (; itList != primaryList.end(); ++itList) {
    std::copy(itList->data.begin(), itList->data.end(),
              std::back_inserter(newContainer));
  }
  std::copy(origin->end() - (origin->size() % (1 << recursionLevel)),
            origin->end(), std::back_inserter(newContainer));
  *origin = newContainer;
  if (recursionLevel == 0)
    return;
  mergeInserts(origin, recursionLevel - 1);
}

// Fase de ordenación por pares recursiva, renombrada a pairSortRecursively.
// Se reemplaza el uso de std::pow por desplazamientos de bits.
template <typename Container>
void pairSortRecursively(Container *origin, unsigned int *recursionLevel) {
  if ((1U << (*recursionLevel)) > origin->size() / 2)
    return;
  typename Container::iterator it =
      origin->begin() + ((1 << (*recursionLevel)) - 1);
  typename Container::iterator it2 =
      origin->begin() + (((1 << ((*recursionLevel) + 1)) - 1));
  typename Container::iterator dummy1, dummy2;
  while (it2 != origin->end()) {
    if (*it > *it2) {
      dummy1 = it;
      dummy2 = it2;
      while (dummy2 != it) {
        std::swap(*dummy1, *dummy2);
        --dummy1;
        --dummy2;
      }
    }
    if (!safeAdvance(it2, origin->end(), (1 << ((*recursionLevel) + 1))))
      break;
    it += (1 << ((*recursionLevel) + 1));
  }
  ++(*recursionLevel);
  pairSortRecursively(origin, recursionLevel);
}

// Función principal que orquesta el proceso de fusión y ordenación, renombrada
// a mergeProcess.
template <typename Container> double mergeProcess(Container *origin) {
  unsigned int recursionLevel = 0;
  clock_t startTime = clock();

  pairSortRecursively(origin, &recursionLevel);
  if (recursionLevel > 0)
	mergeInserts(origin, recursionLevel - 1);

  clock_t endTime = clock();
  return (static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000);
}

// Verifica si el contenedor está ordenado (renombrada a checkSorted)
template <typename Container> void checkSorted(Container &origin) {
  typename Container::iterator it = origin.begin();
  typename Container::iterator it2 = origin.begin();
  ++it2;
  while (it2 != origin.end()) {
    if (*it > *it2) {
      std::cout << "Sequence is NOT sorted!\n";
      std::exit(1);
    }
    ++it;
    ++it2;
  }
}

// Imprime los elementos del contenedor (renombrada a printElements)
template <typename Container> void printElements(Container &origin) {
  typename Container::iterator it = origin.begin();
  for (; it != origin.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

#endif // PMERGE_ME_HPP
