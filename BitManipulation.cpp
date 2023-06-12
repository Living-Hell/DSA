class BitManipulation{
    public:    
    //Given a positive integer N, print count of set bits in it. 
    int setBits(int N) {
        if(N==1) return 1;
        return (N%2) + setBits(N/2);
    }

};

int main(){
    BitManipulation bitsm;

    return 0;
}