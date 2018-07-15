#include<stdio.h>

using namespace std;

int main (){

	int h1, m1, s1, h2, m2, s2, h3, m3, s3;
	
	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);

	h3 = h2 - h1;
	m3 = m2 - m1;
	s3 = s2 - s1;

	if(h1==h2 && m1==m2 && s1==s2){
        printf("24:00:00");
        return 0;
    }

    if(s3 < 0){
		m3 --;
		s3 += 60;
	}

	if(m3 < 0){
		h3 --;
		m3 += 60;
	}
	
	if (h3 < 0)
	{
		h3 += 24;
	}

	printf("%0.2d:%0.2d:%0.2d\n", h3, m3, s3);
	
	return 0;

}