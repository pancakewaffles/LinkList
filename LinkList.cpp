#include <stdio.h>

class LinkList{
    private:
    int *array;
    int *current;
    int l;
    public:
    LinkList(){
    
    }
    LinkList(int *t, int l): l(l){
        array = new int[l];
        for(int i =0;i<l;i++){
            array[i] = *(t++);
        }
        current = array;
    }
    ~LinkList(){
        delete[] array;
    }
    LinkList(const LinkList& x){
        l = x.l;
        array = new int[l];
        for(int i = 0;i<l;i++){
            array[i] = x.array[i];
        }
        current = array;
        
    }
    LinkList& operator=(const LinkList& x){
        l = x.l;
        array = new int[l];
        for(int i = 0;i<l;i++){
            array[i] = x.array[i];
        } 
        current = array;
        
    }
    int pop(){
        if(l > 0){
            l--;
            return *(current++);
        }
        else{
            return -1;
        }
    }
};

int main()
{
    printf("Hello World\n");
    int test[] = {1,2,3,4,5};
    LinkList l1(test+1,4), l2(test,5);
    LinkList l3=l2, l4;
    l4 = l1;
    printf("%d %d %d\n", l1.pop(), l3.pop(), l4.pop());
    return 0;
}
