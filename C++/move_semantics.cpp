// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

class String{
    char *mData;
    uint32_t msize;
    
    public:
    String(const char* ip)
    {
        std::cout<<"Created"<<std::endl;
        msize = strlen(ip);
        mData = new char[msize];
        memcpy(mData,ip,msize);
    }
    
    /*String(const String& ip)
    {
        std::cout<<"Copied"<<std::endl;
        msize = ip.msize;
        mData = new char[msize];
        memcpy(mData,ip.mData,msize);
    }*/
    
    String(String&& ip) noexcept//<== MOVE CONSTRUCTOR
    {
        std::cout<<"moved"<<std::endl;
        msize = ip.msize;
        mData = ip.mData;
        ip.msize = 0;
        ip.mData = nullptr;
    }

    ~String()
    {
        std::cout<<"Destroyed"<<std::endl;
        delete mData;
    }
    
    void Print()
    {
        for (uint32_t i = 0;i<msize;++i)
        {
           std::cout<<mData[i];
        }
        std::cout<<std::endl;
    }
    
};

class Entity{
    String m_name;
    public:
    //Entity(const String &ip) : m_name(ip){}
    Entity(String &&ip) : m_name(std::move(ip)){}

    void Printname()
    {
        m_name.Print();
    }
};

int main() {
Entity entity("Cherno");
entity.Printname();
return 0;
}
