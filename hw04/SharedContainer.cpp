#include <iostream>
#include <map>
#define dict map<int, int>
using namespace std;
class Content {
public:
    explicit Content(int id) : id(id) {
        std::cout << "create " << id << std::endl;
    }

    ~Content() {
        std::cout << "destroy " << id << std::endl;
    }

private:
    int id{-1};
    char data[1024]{};
};

class SharedContainer {
public:
    //TODO
    explicit SharedContainer(int mem_id){
        Content* tmp = new Content(mem_id);
        _data = tmp;
        id = mem_id;
        table[mem_id] = 1;
    }
    //TODO
    ~SharedContainer(){
        table[id]--;
        if(table[id] <= 0){
            delete _data;
        }
    }
    //TODO
    SharedContainer(const SharedContainer &other){
        _data = other._data;
        id = other.id;
        table[id]++;
    }
    //TODO
    SharedContainer& operator=(const SharedContainer &other){
        if(this == &other){
            return *this;
        }
        if(id != other.id){
            if(id != -1){
                table[id]--;
                if(table[id] <= 0){
                    delete _data;
                }
            }
            id = other.id;
            _data = other._data;
            table[id]++;
        }
        return *this;
        
    }
    //TODO
    int get_count() const{
        return table[id];
    }

    SharedContainer(const SharedContainer &&) = delete;
    SharedContainer &operator=(const SharedContainer &&) = delete;

    static dict table;
private:
    Content *_data{nullptr};
    //TODO: design your own reference counting mechanism
    int id{-1};
    
};
dict SharedContainer::table;
void test1(){
    SharedContainer m1(1);
    SharedContainer m2 = m1;
    SharedContainer m3(m2);
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
    std::cout << m3.get_count() << std::endl;
}

void test2(){
    SharedContainer m1(1);
    SharedContainer m2 = m1;
    m1 = m1;
    {
        SharedContainer m3 = m1;
        std::cout << m1.get_count() << std::endl;
    }
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
}

void test3(){
    SharedContainer m1(1);
    SharedContainer m2(2);
    m1 = m2;
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
    {
        SharedContainer m3(3);
        m1 = m3;
        std::cout << m1.get_count() << std::endl;
        std::cout << m2.get_count() << std::endl;
        std::cout << m3.get_count() << std::endl;
    }
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;

}

int main(){
    test1();
    test2();
    test3();
    return 0;
}