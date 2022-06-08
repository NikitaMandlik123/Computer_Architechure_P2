#include "project02.h"
using namespace std;
  

int inputSize(FILE *file);


int counter;

int main(int argc, char *argv[]){
    unsigned char *HexFormat;
	//char elements[];
	//char line[];	
    //FETCH
    FILE *file ;
    // Opens file in read mode	
	if ((file =fopen(argv[1], "rb"))==NULL)
       cout<< "File not open"<<endl;
    else
        cout<<"File Opened Successfully"<<endl;   
       
    long fileSize = inputSize(file);
    
    
     //DECODE
     //Converts the binary file into hexadecimal (decoding)
	HexFormat = new unsigned char[fileSize];
        request_done =-1;
	fread(HexFormat, fileSize, 1, file);
	        
	 Simple_Pipe simple_pipe;
    	for(int i = 0; i < REG_COUNT; i++){
       	 simple_pipe.registers[i] = 0;
   	 }
    
	int opcode, d, lo,ro;
	int i =0;
    for(i=0;i<=600;i+=4){
        request_done++;	
	
	opcode = (int)HexFormat[i+3];
	d = (int)HexFormat[i+2];
	lo = (int)HexFormat[i+1];
	ro = (int)HexFormat[i+0];

   

 
	
    //EXECUTE
            switch (opcode)
            {
            case 0://setting the register
                simple_pipe.registers[d] = lo;
                
				counter++;
                
                break;

            case 16://addding type1
                simple_pipe.registers[d] = simple_pipe.registers[lo] + simple_pipe.registers[ro];
				counter++;
                
                break; 


            case 17://adding type2
                simple_pipe.registers[d] = simple_pipe.registers[lo] + ro;
				counter=counter+1;
                break;


            case 32://subtraction type1
                simple_pipe.registers[d] = simple_pipe.registers[lo] - simple_pipe.registers[ro];
				counter=counter+1;
                break;

            case 33://subtraction type2
                simple_pipe.registers[d] = simple_pipe.registers[lo] - ro;
				counter= counter+1;
                break;

            case 48://multiplication type1
                simple_pipe.registers[d] = simple_pipe.registers[lo] * simple_pipe.registers[ro];
				counter=counter+2;
                break;       


            case 49://multiplication type2
                simple_pipe.registers[d] = simple_pipe.registers[lo] * ro;
				counter=counter+2;
                break; 


            case 64://division type1
                simple_pipe.registers[d] = simple_pipe.registers[lo] / simple_pipe.registers[ro];
				counter=counter+4;
                break; 

            case 65://division type2
                simple_pipe.registers[d] = simple_pipe.registers[lo] / ro;
				counter=counter+4;
                break;                        
            }
           
	}


    	
    execution_time= counter +1; 	
    simple_pipe.print_regs();
    std::cout << "Total execution cycles: " << execution_time << std::endl;
    std::cout << "\nIPC: " << (request_done/(double)execution_time) << std::endl << std::endl;
	
	
    return 0;
}



void Simple_Pipe::print_regs(){
    printf("\nRegisters: \n");
    std::cout << "----------------------------------------" << std::endl;
    for(int i = 0; i < REG_COUNT; i+=2){
        std::string regl("R");
        regl.append(std::to_string(i));
        regl.append(": ");

        std::string regr("R");
        regr.append(std::to_string(i+1));
        regr.append(": ");
        if(i < 15){
            std::cout << "  " << std::setiosflags(std::ios::left) 
            << std::setw(5) << regl  << std::setw(10) << registers[i] << " |   " 
            << std::setw(5) << regr << std::setw(10) << registers[i+1] << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }else{
            std::cout << "  " << std::setiosflags(std::ios::left) 
            << std::setw(5) << regl << std::setw(10) << registers[i] << " |   " << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    }  
    printf("\n");
}

int inputSize(FILE *input)
{
	
    int init = ftell(input);
	fseek(input, 0, 2);
	
    int end = ftell(input);
	fseek(input, init, 0);
	return end;
}

