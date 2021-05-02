#include <iostream>
#include <vector>

// using namespace avl;

namespace avl {											
template <typename Key, typename Cmp = std::less<Key>>			
class Set final {										
public:		
    struct node
    {
        Key value;
        node* left;
        node* right;
        node* prev;
    };
    int set_size = 0;
    // node* front_node;
    // node* back_node;
    node* main_node;

    Set()
    {
        // this->front_node = nullptr;
        // this->back_node = nullptr; 
        this->main_node = nullptr;
    } // конструктор без параметров создаёт пустое дерево	


    ~Set()
    {

    } // деструктор при необходимости					

    /*												
     * Ищет элемент в множестве и возвращает булево значение:		
     * true – элемент содержится в множестве,					
     * false – элемент не содержится в множестве.				
     * */												
    bool find(Key const & x) const
    {
        if (this->main_node == nullptr) {
            return false;
        } else {
            node* MyNode = this->main_node;
            while (true) 
            {
                // std::cout << "eftrhyum" << std::endl;
                if (MyNode->value == x) {
                    return true;
                }
                if (x > MyNode->value) {
                    if (MyNode->left == nullptr) {
                        return false;
                    } else {
                        MyNode = MyNode->left;
                    }
                } else {
                    if (MyNode->right == nullptr) {
                        return false;
                    } else {
                        MyNode = MyNode->right;
                    }
                }
            }
            // std::cout << "eftrhyum------" << std::endl;
            // std::cout << MyNode->value << std::endl;
            if (MyNode->value == x) {
                return true;
            } else {
                return false;
            }
        }
    }							
													
    using size_type = int; // количественный тип			
    size_type size() const
    {
        return this->set_size;
    } // количество элементов в множестве		
    													
    /*												
     * Добавляет элемент в множество и возвращает булево значение:	
     * true - элемент новый,								
     * false - элемент уже содержался в множестве.				
     * */				

    bool insert(Key const & x)
    {
        if (this->set_size == 0) {
            node* MyNode = new node;
            this->main_node = MyNode;
            this->main_node->prev = nullptr;
            MyNode->value = x;
            MyNode->left = nullptr;
            MyNode->right = nullptr; 
            // this->front_node = MyNode;
            // this->back_node = MyNode;
            this->set_size += 1;
            // std::cout << "tat" << std::endl;
            return true;
        } else {
            if (find(x)) return false;
            // std::cout << "tut" << std::endl;
            node* MyNode = this->main_node;
            while (true) 
            {   
                // std::cout << "aga " << MyNode->value << std::endl;
                if (MyNode->value > x && MyNode->right == nullptr) {
                    node* ThisNode = new node;
                    ThisNode->prev = MyNode;
                    ThisNode->value = x;
                    ThisNode->left = nullptr;
                    ThisNode->right = nullptr;
                    MyNode->right = ThisNode; 
                    this->set_size += 1;
                    return true;
                } else if (MyNode->value < x && MyNode->left == nullptr) {
                    node* ThisNode = new node;
                    ThisNode->prev = MyNode;
                    ThisNode->value = x;
                    ThisNode->left = nullptr;
                    ThisNode->right = nullptr;
                    MyNode->left = ThisNode; 
                    this->set_size += 1;
                    return true;
                } else if (MyNode->value < x) {
                    // std::cout << "aga11 " << MyNode->value << std::endl;
                    MyNode = MyNode->left;
                } else if (MyNode->value > x) {
                    // std::cout << "aga22 " << MyNode->value << std::endl;
                    MyNode = MyNode->right;
                } 
            }
        }

    }

    void PrintSet1()
    {
        std::cout << "\"";
        bool is_first = true;
        for (auto it = front(); it != back(); it = next(it))
        {
            if (!is_first)
                std::cout << " ";
            is_first = false;
            std::cout << it->value;
        }
        if (back() != nullptr)
        {
            if (!is_first)
                std::cout << " ";
            std::cout << back()->value;
        }
        std::cout << "\"";
    }

    void print()
    {
        if (size() == 0) 
        {
            std::cout << "--0--" << std::endl;
        }
        else
        {
            if (this->main_node != nullptr) std::cout << "--" << this->main_node->value << "--" << std::endl;
            std::cout << "--";
            if (this->main_node->left != nullptr) std::cout << this->main_node->left->value;
            std::cout << "--" ;
            if (this->main_node->right != nullptr) std::cout << this->main_node->right->value;
            std::cout << std::endl;
            std::cout << "--";
            if (this->main_node->left->left != nullptr) std::cout << this->main_node->left->left->value;
            std::cout << "--" ;
            if (this->main_node->left->right != nullptr) std::cout << this->main_node->left->right->value;
            std::cout << "--";
            if (this->main_node->right->left != nullptr) std::cout << this->main_node->right->left->value;
            std::cout << "--" ;
            if (this->main_node->right->right != nullptr) std::cout << this->main_node->right->right->value;
            std::cout << std::endl;
        }
        
    }

											
    /*												
     * Удаляет элемент из множества и возвращает булево значение:	
     * true – элемент содержался в множестве и был успешно удалён,	
     * false – элемент не содержался в множестве.				
     * */												
    bool erase(Key const & x)
    {
        if (!find(x)) return false;
        node* MyNode = this->main_node;
        while (true) 
        {
            // std::cout << "eftrhyum" << std::endl;
            if (MyNode->value == x) {
                break;
            }
            if (x > MyNode->value) {
                MyNode = MyNode->left;
            } else {
                MyNode = MyNode->right;
            }
        }
        // std::cout << MyNode->value;
        if (MyNode->left == nullptr && MyNode->right == nullptr) {
            if (MyNode == this->main_node) {
                this->main_node = nullptr;
            } else {
                node* PrevNode = MyNode->prev;
                // std::cout << PrevNode->value;
                if (PrevNode->left == MyNode) {
                    PrevNode->left = nullptr;
                } else {
                    PrevNode->right = nullptr;
                }
            }
            delete MyNode;
            return true;
        } else if ((MyNode->left == nullptr && MyNode->right != nullptr) || (MyNode->left != nullptr && MyNode->right == nullptr)) {
            if (MyNode->left != nullptr) {
                if (MyNode == this->main_node) {
                    this->main_node = MyNode->left;
                    MyNode->left->prev = nullptr;
                } else {
                    node* PrevNode = MyNode->prev;
                    if (PrevNode->left == MyNode) {
                        PrevNode->left = MyNode->left;
                    } else {
                        PrevNode->right = MyNode->left;
                    }
                    MyNode->left->prev = PrevNode;
                    // std::cout << PrevNode->left->value;
                }
            } else if (MyNode->right != nullptr) {
                if (MyNode == this->main_node) {
                    this->main_node = MyNode->right;
                    MyNode->right->prev = nullptr;
                } else {
                    node* PrevNode = MyNode->prev;
                    if (PrevNode->left == MyNode) {
                        PrevNode->left = MyNode->right;
                    } else {
                        PrevNode->right = MyNode->right;
                    }
                    MyNode->right->prev = PrevNode;
                    // std::cout << PrevNode->left->value;
                }
            }
            delete MyNode;
            return true;
        } else {
            if (MyNode == this->main_node) {
                // std::cout << "tuta" << std::endl;
                node* LeftNode = MyNode->left;
                // std::cout << "tuta0 " << LeftNode->value << std::endl;
                while (LeftNode->right != nullptr) {
                    // std::cout << "tuta1" << std::endl;
                    LeftNode = LeftNode->right;
                }
                // std::cout << "tuta21 " << (LeftNode->right == nullptr) << std::endl;
                LeftNode->right = MyNode->right;
                // std::cout << "tuta2 " << LeftNode->right->value << std::endl;
                MyNode->rightоиprev = LeftNode;
                this->main_node = MyNode->left;
                this->main_node->prev = nullptr;
            } else {
                node* PrevNode = MyNode->prev;
                if (PrevNode->left == MyNode) {
                    PrevNode->left = MyNode->left;
                } else {
                    PrevNode->right = MyNode->left;
                }
                MyNode->left->prev = PrevNode;
                node* LeftNode = MyNode->left;
                while (LeftNode->right != nullptr) {
                    LeftNode = LeftNode->right;
                }
                LeftNode->right = MyNode->right;
                MyNode->right->prev = LeftNode;
            }
            delete MyNode;
            return true;
        }
    }							
													
/*												
* Тип данных, используемые для обхода и					
* получения значения ключа.								
* */			

using iterator = node*;								
													
iterator front() const // итератор на первый элемент	
{
    if (this->main_node == nullptr) {
        return nullptr;
    } else {
        iterator MyNode = this->main_node;
        while (MyNode->right != nullptr) {
            MyNode = MyNode->right;
        }
        return MyNode;
    }
}

iterator back() const // итератор на последний элемент
{
    if (this->main_node == nullptr) {
        return nullptr;
    } else {
        iterator MyNode = this->main_node;
        while (MyNode->left != nullptr) {
            MyNode = MyNode->left;
        }
        return MyNode;
    }
}	

iterator next(iterator px) const
{
    if (this->main_node == nullptr) {
        return nullptr;
    } else {
        if (px->left != nullptr) {
            iterator MyNode = px->left;
            while (true) {
                if (MyNode->right != nullptr) {
                    MyNode = MyNode->right;
                } else {
                    return MyNode;
                }
            }
        } else if (px == back()) {
            return nullptr;
        } else {
            if (px == px->prev->right) {
                // std::cout << "next1 " << px->value << " " << px->prev->value << std::endl;
                return px->prev;
            } else {
                iterator MyNode = px;
                while (true) {
                    if (MyNode->prev == this->main_node) {
                        return MyNode->prev;
                    } else if (MyNode->prev->right == MyNode) {
                        // std::cout << " agaaga ";
                        return MyNode->prev;
                    }
                    MyNode = MyNode->prev;
                }
                
            }
        }
    }
} // получение итератора на следующий элемент	

iterator previo(iterator px) const
{
    if (this->main_node == nullptr) {
        return nullptr;
    } else {
        if (px->right != nullptr) {
            iterator MyNode = px->right;
            while (true) {
                if (MyNode->left != nullptr) {
                    MyNode = MyNode->left;
                } else {
                    return MyNode;
                }
            }
        } else if (px == front()) {
            return nullptr;
        } else {
            if (px == px->prev->left) {
                return px->prev;
            } else {
                iterator MyNode = px;
                while (true) {
                    if (MyNode->prev == this->main_node) {
                        return MyNode->prev;
                    } else if (MyNode->prev->left == MyNode) {
                        // std::cout << " agaaga ";
                        return MyNode->prev;
                    }
                    MyNode = MyNode->prev;
                }
                
            }
        }
    }

} // получение итератора на предыдущий. элемент												
};													
} /* avl namespace */ 



// int main()
// {
//     avl::Set <int> s;
//     
//     return 0;
// }