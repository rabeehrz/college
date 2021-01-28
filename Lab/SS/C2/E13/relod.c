#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char[], char[]);

void main()
{
	FILE *objcode;
	int start_addr_in_mem, start_addr_in_prgrm;
	int prgrm_len, line_len, addr = 0, addr_in_mem, i = 0;
	char record_code, prgrm_name[10], prgrm_line[80];
	char *token, bitmask[30], binary_str[120], *opcode;

	if(! (objcode = fopen("objcode.txt", "r")))
	{
		printf("Please save the object code as objcode.txt\n");
		exit(0);
	}

	printf("Enter starting address in memory: ");
	scanf("%x", &start_addr_in_mem);

	while(! feof(objcode))
	{
		fscanf(objcode, "%c", &record_code);
		switch(record_code)
		{
			case 'H':
				fscanf(
					objcode, 
					"^%[^^]^%x^%x", 
					prgrm_name, 
					&start_addr_in_prgrm, 
					&prgrm_len
				);
				break;
			
			case 'T':
				fscanf(
					objcode, 
					"^%x^%x^%[^^]^%s", 
					&addr, 
					&line_len, 
					bitmask, prgrm_line
				);
				addr += start_addr_in_mem;
				convert(bitmask, binary_str);
				
				i = 0;

				// Splitting string with delimiter ^
				token = strtok(prgrm_line, "^");
				while(token != NULL)
				{
					addr_in_mem = (int) strtol(
						strtok(NULL, "^"),
						NULL,
						16
					);

					addr_in_mem = (binary_str[i++] == '0') 
						? addr_in_mem
						: addr_in_mem+start_addr_in_mem;
					printf("%x %s%x\n", addr, token, addr_in_mem);
					addr += 3;
					token = strtok(NULL, "^");
				}
				break;
			
			case 'E':
				exit(0);
		}
	}

	fclose(objcode);
}

void convert(char bitmask[], char binary_str[])
{
	int len = strlen(bitmask);
	strcpy(binary_str, "");
	
	for(int i = 0; i < len; i++)
	{
		switch(bitmask[i])
		{
			case '0':
				strcat(binary_str, "0000");
				break;
			case '1':
				strcat(binary_str, "0001");
				break;
			case '2':
				strcat(binary_str, "0010");
				break;
			case '3':
				strcat(binary_str, "0011");
				break;
			case '4':
				strcat(binary_str, "0100");
				break;
			case '5':
				strcat(binary_str, "0101");
				break;
			case '6':
				strcat(binary_str, "0110");
				break;
			case '7':
				strcat(binary_str, "0111");
				break;
			case '8':
				strcat(binary_str, "1000");
				break;
			case '9':
				strcat(binary_str, "1001");
				break;
			case 'A':
				strcat(binary_str, "1010");
				break;
			case 'B':
				strcat(binary_str, "1011");
				break;
			case 'C':
				strcat(binary_str, "1100");
				break;
			case 'D':
				strcat(binary_str, "1101");
				break;
			case 'E':
				strcat(binary_str, "1110");
				break;
			case 'F':
				strcat(binary_str, "1111");
				break;
		}
	}
}