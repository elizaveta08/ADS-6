// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {// реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T arr[100];
    int first;  // Указатель на первый элемент очереди
    int last;   // Указатель на конец очереди

 public:
     TPQueue():first(0), last(0) { }
     void push(T x) {
         if (last - first >= size)
             throw std::string("Full!");
         else {
            int q = last;
            while ((--q >= first) && (arr[q % size].prior < x.prior)) {
                arr[(q + 1) % size] = arr[q % size];
            }
            arr[(q + 1) % size] = x;
            last++;
         }
     }
     T pop() {
       return arr[(first++) % size];
     }
     int getSize() {
       return (last-first);
     }
     T front() {
         return arr[first%size];
     }
     T back() {
         return arr[(last-1)%size];
     }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
