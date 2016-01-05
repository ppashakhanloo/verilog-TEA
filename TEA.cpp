#include <iostream>
#include <stdint.h>

using namespace std;

void encrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0, i;           /* set up */
    uint32_t delta=10;                     /* a key schedule constant */
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i < 32; i++) {                       /* basic cycle start */
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}

int main() {
	uint32_t v[] = {13, 17};
	uint32_t k[] = {5, 4, 3, 7};
	encrypt(v, k);
	cout << "v=" << endl << v[0] << "\\" << v[1] << endl;
	return 0;
}
