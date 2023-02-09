#include "iostream"
using namespace std;

template<typename T>
class CNode
{
    private:
        T data;
        CNode<T>* next;
        template<typename U> friend class LLCart;
    public:
        CNode()
        {
            this->next = NULL;
        }
};

template<typename T> 
class LLCart
{
    private:
        CNode<T>* head;
        int cartSize = 0;
    public:
        LLCart()
        {
            this->head = NULL;
        }

        void addCake(T prod)
        {
            CNode<T>* cake = new CNode<T>;
            cake->data = prod;
            if(head == NULL)
            {
                head = cake;
                cartSize++;
                cout << "Cake Added to cart!!!" << endl;
                return;
            }

            CNode<T>* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = cake;
            cartSize++;
            cout << "Cake Added" << endl;
        }

        void removeCake(int uid)
        {
            int size = GetCartSize();
            if(head == NULL || size == 0)
            {
                cout << "Cart is empty";
                return;
            }

            if(size == 1)
            {
                head = head->next;
                return;
            }
            int counter = 0;
            CNode<T>* temp = head;
            while (temp != NULL)
            {
                
                if(uid == temp->next->data && counter != size)
                {
                    temp->next = temp->next->next;
                    cout << "Cake Removed" << endl;
                    cartSize--;
                    return;
                }else if(uid == temp->data)
                {
                    removeAtEnd();
                    return;
                }
                temp = temp->next;
                counter++;
            }
            
        }

        void DisplayCart()
        {
            CNode<T>* temp = head;
            while (temp != NULL)
            {
                cout<< temp->data << " -> ";
                temp = temp->next;
            }
            
        }

        void removeAtEnd()
        {
            CNode<T>* temp = head;
            while (temp != NULL)
            {
                if(temp->next->next == NULL)
                {
                    temp->next = NULL;
                    cout << "Cake Removed" << endl;
                    break;
                }
                temp = temp->next;
            }
            
        }

        int GetCartSize()
        {
            return cartSize;
        }
};



int main()
{
    LLCart<int> list;
    list.addCake(5);
    list.addCake(56);
    list.addCake(36);
    list.addCake(12);
    list.addCake(569);
    list.addCake(536);
    list.addCake(53346);
    list.addCake(5236);
    list.addCake(5346);
    list.addCake(54256);
    list.addCake(66);
    list.DisplayCart();
    list.removeCake(569);
    list.DisplayCart();
    list.removeCake(5);
    list.DisplayCart();
}