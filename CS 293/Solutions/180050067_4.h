#include<vector>
#define vec std::vector<T>

template <class T>
class myvector {
      int v_size;
      vec v;
      int index;
public:
      void push_front(T x) {
            if (index) {
                  v_size++;
                  index--;
                  v[index] = x;
            }
            else {
                  if (v_size) {
                        vec back(2 * v_size);
                        for (int i = v_size; i < 2 * v_size; i++)
                              back[i] = v[index++];
                        v = back;
                        index = v_size;
                        v[--index] = x;
                        v_size++;
                  }
                  else {
                        vec front;
                        front.push_back(x);
                        v = front;
                        v_size++;
                        index = 0;
                  }
            }
      }
      void push_back(T x) {
            v.push_back(x);
            v_size++;
      }
      void pop_front() {
            if (v_size) {
                  index++;
                  v_size--;
            }
      }
      void pop_back() {
            if (v_size) {
                  v.pop_back();
                  v_size--;
            }
      }
      int size()  const {
            return v_size;
      }
      T & operator[](int i) {
            return v[index + i];
      }
      myvector<T>() {
            v_size = 0;
            index = 0;
      }
};