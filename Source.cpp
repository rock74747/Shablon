#include <iostream>
#include <algorithm>
#include <vector>
template <typename T>
 class list {
    public:
        list()
            : start(nullptr),
            end(nullptr),
            size_(0) {}
       
        ~list() {
            start = end = nullptr;
        }

        void push_front(const T& data) {
            Node* ptr = new Node(data);
            ptr->next_ = start;
            if (start != 0)
                start->prev_ = ptr;
            if (end == 0) {
                end = ptr;
            }
            start = ptr;
            size_++;
        }
         void push_back(const T& data) {
            Node* ptr = new Node(data);
            ptr->prev_ = end;
            if (end != 0)
                end->next_ = ptr;
            if (start == 0) {
                start = ptr;
            }
            end = ptr;
            size_++;
        }
        void pop_front() {
            if (start == 0) return;
            Node* ptr = start->next_;
            if (ptr != NULL)
                ptr->prev_ = NULL;
            else
                end = NULL;
            delete start;
            start = ptr;
        }
        void  pop_back() {
            if (end == 0) return;
            Node* ptr = end->prev_;
            if (ptr != NULL)
                ptr->next_ = NULL;
            else
                start = NULL;
            delete end;
            end = ptr;
        }
        T& operator[](int i) {
            int count{};
            Node* ptr = start;
            while (count < i) {
                ptr = ptr->next_;
                count += 1;
            }
            return ptr->data_;
        }

        const T& operator[](int i)const {
            int count{};
            Node* ptr = start;
            while (count < i) {
                ptr = ptr->next_;
                count += 1;
            }
            return ptr->data_;
        }

        void insert(int index, const T& data) {
            Node* ptr = new Node(data);
            if (index >= size_) {
                return push_back(data);
            }
            if (index == 0) {
                return push_front(data);
            }
            else {
                Node* prev_ = get_node(index - 1);
                Node* next_ = prev_->next_;
                prev_->next_ = ptr;
                ptr->prev_ = prev_;
                ptr->next_ = next_;
                if (next_)
                    next_->prev_ = ptr;
                if (prev_ == end)
                    end = ptr;
            }
        }
        void erise(int index) {
            Node* ptr = get_node(index);
            if (ptr == NULL)
                return;
            if (ptr->prev_ == NULL) {
                pop_front();
                return;
            }
            if (ptr->next_ == NULL) {
                pop_back();
                return;
            }
            Node* left = ptr->prev_;
            Node* rigth = ptr->next_;
            left->next_ = rigth;
            rigth->prev_ = left;
            delete ptr;
        }
        void print() const {
            for (Node* ptr = start; ptr != end; ptr = ptr->next_)
            {
                std::cout << ptr->data_ << ' ';
            }
            std::cout << std::endl;
        }
   

protected:
        class Node {
            friend class list <T>;
            T data_;
            Node* next_;
            Node* prev_;

        public:
            Node()
                :Node(T()) {}
            Node(const T data) {
                this->data_ = data;
                this->next_ = NULL;
                this->prev_ = NULL;
            }
            ~Node() = default;
        };
       
        Node* start;
        Node* end;
        int size_;

        Node* get_node(int index) {
            if (index < 0)
                throw - 1;
            Node* current = start;
            for (int i = 0; i < index; i++) {
                if (!current)
                    break;
                current = current->next_;
            }
            if (!current)
                throw - 1;
            return current;
        }
    };

   

    template <typename T>
    class dynamic_array{
    private:
        int m_size;
        int m_capacity;
        T* m_data;

    public:
        dynamic_array()
        {
            m_size = 0;
            m_capacity = 0;
            m_data = NULL;
        }

        dynamic_array(const dynamic_array<T>& a) // конструктор копирования
        {
            m_size = a.m_size;
            m_capacity = m_size;
            m_data = NULL;
            if (m_size != 0)
                m_data = new T[m_size];
            else
                m_data = 0;
            for (int i = 0; i < m_size; ++i)
                m_data[i] = a.m_data[i];
        }

        dynamic_array(int size)
        {
            m_size = size;
            m_capacity = size;
            if (size != 0)
                m_data = new T[size];
            else
                m_data = 0;
        }

        ~dynamic_array()
        {
            if (m_data)
                delete[] m_data;
        }

        int resize(int size) // изменение размера массива
        {
            if (size > m_capacity)
            {
                int new_capacity = std::max (size, m_size*2);
                T* new_data = new T[new_capacity];
                for (int i = 0; i < m_size; ++i)
                    new_data[i] = m_data[i];
                delete[] m_data;
                m_data = new_data;
                m_capacity = new_capacity;
            }
            return m_size = size;
        }

        void push_back(T val)
        {
            resize(m_size + 1);
            m_data[m_size - 1] = val;
        }

        int size() const
        {
            return m_size;
        }

        T& operator[] (int i)
        {
            return m_data[i];
        }
    };

    template<typename T>
    std:: ostream& operator << (std:: ostream& out, dynamic_array<T> a)
    {
        for (int i = 0; i < a.size(); ++i)
            out << a[i] << " ";
        return out;
    }

int main()
{
    system("chcp 1251>null");

    list <double> one;
    for (int i = 0; i < 10; i++)
    {
        one.push_back(i);
    }
    one.print();
    std::cout << std::endl;

    one.push_front(10.3);
    one.print();

    std::cout << std::endl;
    one.insert(2, 30.6);
    one.print();
    std::cout << std::endl;

    // Очередь можно реализовать на основе List и функций push_front и   pop_back.

    dynamic_array <int> to;
    for (int i = 0; i < 6; i++)
    {
        to.push_back(i);
    }
   
    for (int i = 0; i < to.size(); ++i)
        std:: cout << to[i] << " ";
        std::cout << std::endl;
   
        std::cout << to[3];

    return 0;
}





