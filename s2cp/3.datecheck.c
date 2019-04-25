#include<stdio.h>

void main() {
	/* 12/5/1978 to 03/07/2015*/
	int d,m,y,flag;
	printf("Enter date, month and year: ");
	scanf("%d%d%d",&d,&m,&y);
	if (y<1978 || y>2015)
		printf("Invalid Year!\n");
	else {
		if(m<1 || m>12) {
			printf("Invalid month!\n");
		} else if ((m<5 && y==1978) || (m>7 && y==2015)) {
			printf("Date not in range.\n");
		} else {
			if(d>31 || d<1) {
				printf("Invalid date!\n");
			} else {
				switch(m) {
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						if(d>31) {
							flag=1;
						}
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						if(d>30) {
							flag=1;
						}
						break;
					case 2:
						if((y%4 == 0 && d>29) || (y%4 != 0 && d>28)) {
							flag = 1;
						}
						break;
				}
				if (flag == 1) {
					printf("Invalid date for month!\n");
				} else {
					if((d<12 && m==5) || (d>3 && m==7)) {
						printf("Not in range!\n");
					} else {
						printf("Date is in range!\n");
					}
				}
			}
		}
	}
}
