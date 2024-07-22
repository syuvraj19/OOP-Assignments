#ifndef main_h
#define main_h

using namespace sdds{
    
    class RecordSet{
        
        char* xstring;
        char* string_count;
        
    public:
        RecordSet();//default constructor
        
        RecordSet(const RecordSet &src);//custom constructor
        
        ~RecordSet();//destructor
        
        
    };
    
}



#endif /* main_h */
