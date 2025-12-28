#include<stdio.h>
int asalKontrol(int n){
    if (n <2)
    return 0;
    for( int i=2;i*i<=n;i++){
        if(n %i==0)
        return 0;
    }
    return 1;
}
int main(){
    int count =0;
    printf("Gecerli Isimler :\n");
    for(char a='a'; a<='z'&& count <47;a++){
        for(char b='b';b <='z'&& count <47;b++){
            char c= a;
            int aUnlu =(a=='a'|| a=='i'|| a=='e'|| a=='u'|| a=='o');
            int bUnlu=(b=='a'|| b=='i'|| b=='e'|| b=='u'|| b=='o');
            if((aUnlu && !bUnlu) || (! aUnlu && bUnlu)){
                int toplam =a+b+c;
                int asalmi =1;

                if(toplam <2){
                    asalmi=0;
                }else{
                    for(int i=2; i< toplam; i++){
                        if (toplam %i==0){
                            asalmi=0;
                            break;
                        }
                    }
                }
                if(asalmi == 1){
                    count++;
                    printf("%d.%C%C%C\n",count,a,b,c);
                }
            }
        }
    }
    return 0;
}