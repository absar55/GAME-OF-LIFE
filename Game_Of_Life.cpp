/*
Name:  			Muhammad Absar Khalid
Student ID:		i19-2176
Programming Fundamental Final Project
Class Section:  	E
Lab Section:		B
*/
#include <iostream>//Including Input Output Library
#include <iomanip>//For Better Text Formet
#include <fstream>//Including File Handling Library
using namespace std;//For cin and cout
int cell_status[900][2],cell_neighbours[900][8][2],cells,counter4=0,shared_neighbours[900][2],lesser_x=0,lesser_y=0;
int count_remainers=0,count_borns=0,temp_remainers[900][2],temp_borns[900][2],generations,greater_x=-1,greater_y=-1;
int range_x=0,range_y=0;	//Declaring Variables
int **grid1=new int*[20];	//Declaring Dynamic Array
bool extend_top=0,extend_bottom=0,active=0;//Declaring 2-Byte Bool
int data_reader();	//Declaring Function for Reading data from txt File
int displayer();	//Declaring Function for Displaying of Grid
int extended_displayer();//Declaring Function to display extended grid than 20*20 Cell
int neighbours();	//Declaring Function for Calculating Neighbours
int borner();		//Declaring Function to calculate newly born cells
int collector();	//Declaring Function for collection of newly born cells and remaining cells
int rearranger();	//Declaring Function to arrange cells in accending order
int greater_lower_decider();//Declaring Function to decide whether a grid will be extend from top or from bottom.
int dynamic_maker();		//Declaring Function to form a Dynamic Grid Array
int data_writer();		//Declaring Function to write resultant data of cells to file
int dynamic_remover();		//Declaring Function to delete all dynamic arrays and variables
int main()		//Declaring Main Function
{
data_reader();			//Calling Function for Reading data from txt File
int array[20][20];		//Declaring Array
cout<<setw(48)<<"Game Of Life\n";//Displaying info
int counter=0;			//Declaring Variable
rearranger();			//Calling function to arrange cells in accending order
cout<<"Grid Before Generations :\n";//Displaying 
displayer();			//Calling Function for Displaying of Grid
	for (counter=0;counter<generations;counter++)//Using For Loop
	{

		neighbours();	//Calling Function for Calculating Neighbours
		borner();	//Calling Function to calculate newly born cells
		collector();	//Calling Function for collection of newly born cells and remaining cells
		rearranger();	//Calling Function to arrange cells in accending order
		greater_lower_decider();//Calling Function to decide whether a grid will be extend from top or from bottom.
		dynamic_maker();	//Calling Function to form a Dynamic Grid Array
		cout<<"Generation "<<counter+1<<" :\n";//Displaying
			if ((extend_bottom==0) && (extend_top==0))
			{	
				displayer(); //Calling Function for Displaying of Grid
			}
			if ((extend_bottom==1) || (extend_top==1))
			{	
				extended_displayer();	//Calling Function for Displaying of Extended-Grid
			}
	}
dynamic_remover();	//Calling Function to delete all dynamic arrays and variables
data_writer();		//Calling Function to write resultant data of cells to file
return 0;		//Returning 0 to Operating System
}
int data_reader()	//Declaring Function for Reading data from txt File
{
int counter=0;//Declaring 4-Byte Variable
fstream reader;//Declaring Header File
reader.open("input.txt",ios::in);//Opening File
if (reader)	//Conditional Statement if reading in a file correctly
{
reader>>generations;	//Assigning Literals to Variables
reader>>cells;		//Assigning Literals to Variables

	for (counter=0;counter<cells;counter++)//Using For Loop
	{	
	reader>>cell_status[counter][0]>>cell_status[counter][1];//Assigning Literals to Variables
	}
}
else 
{
cout<<"Error in Reading Data File.\n";//Conditional Statement For Error in file reading
}


reader.close();//Closing File
}
int displayer()//Declaring Function for Displaying of Grid
{
int counter=0,counter1=0,counter2=0,counter3=0;//Declaring 4-Byte Variables
char dot=' ';					//Declaring 2-Byte Variable
	for (counter=0;counter<20;counter++)//Using For Loop
	{
		if (counter==0)	//Conditional Statement
		{
			for (counter2=0;counter2<20;counter2++)//Using For Loop
			{
			cout<<"____";	//Displaying 
			}
		}
	cout<<"\n";//Displaying
		for (counter1=0;counter1<20;counter1++)//Using For Loop
		{
			if (counter1==0)//Conditional Statement
			{
				cout<<"|";//Displaying
			}		
		cout<<"   |";//Displaying
		}
		cout<<endl;//Displaying
		for (counter1=0;counter1<20;counter1++)//Using For Loop
		{	
			if (counter1==0)//Conditional Statement
			{
				cout<<"|";//Displaying
			}
			if ((counter1==cell_status[counter3][0]) && (counter==cell_status[counter3][1])) //Conditional Statement
			{
			dot='*';//Assigning Literals to Variable
			counter3++;//Increment
			}
			else 
			{
			dot=' ';//Assigning Literals to Variable
			}
		cout<<"_"<<dot<<"_|";//Displaying
		}
	}

cout<<endl;//Displaying
}
int extended_displayer()//Declaring Function for Displaying of Extended-Grid
{
int counter=0,counter1=0,counter2=0,counter3=0;// Declaring 4-Byte Variables
char dot=' ';					//Declaring 2-Byte Variables
if (extend_bottom==1)				//Conditional Statement
{
range_x=(greater_x+2);				//Assigning Literals to Variable
range_y=(greater_y+2);				//Assigning Literals to Variable
}
if (extend_top==1)				//Using For Loop
{
	for (counter=0;counter<cells;counter++)//Using For Loop
	{
		if ((cell_status[counter][0]<=-1) || (cell_status[counter][1]<=-1))
		{
			active=1;		//Assigning Literals to Variable
		}
	}
	if (active==1)		//Conditional Statement
	{
	range_x=(lesser_x*-1)+22;		//Assigning Literals to Variable
	range_y=(lesser_y*-1)+22;		//Assigning Literals to Variable

		for (counter=0;counter<cells;counter++)//Using For Loop
		{
			cell_status[counter][0]=((cell_status[counter][0])+((lesser_x*-1)+2));//Assigning Literals to Variable
			cell_status[counter][1]=((cell_status[counter][1])+((lesser_x*-1)+2));//Assigning Literals to Variable
		}
	}
	active=0;				//Assigning Literals to Variable
cout<<range_x<<"  Range  "<<range_y<<endl;	//Displaying
}

	for (counter=0;counter<=range_y;counter++)//Using For Loop
	{
		if (counter==0)			//Conditional Statement
		{
			for (counter2=0;counter2<=range_x;counter2++)//Using For Loop
			{
			cout<<"____";		//Displaying
			}
		}
	cout<<"\n";//Displaying
		for (counter1=0;counter1<=range_x;counter1++)//Using For Loop
		{
			if (counter1==0)	//Conditional Statement
			{
				cout<<"|";//Displaying
			}		
		cout<<"   |";//Displaying
		}
		cout<<endl;//Displaying
		for (counter1=0;counter1<=range_x;counter1++)//Using For Loop
		{	
			if (counter1==0)		//Conditional Statement
			{
				cout<<"|";//Displaying
			}
			if ((counter1==cell_status[counter3][0]) && (counter==cell_status[counter3][1])) //Conditional Statement
			{

			dot='*';//Assigning Literal in a Variable
			counter3++;//Increment
			}
			else //Condtional Statement
			{
			dot=' ';//Assigning Literal in a Variable
			}
\
		cout<<"_"<<dot<<"_|";//Displaying
		}
	}

cout<<endl;//Displaying
}


int neighbours()	//Declaring Function for Calculating Neighbours
{
for (int counter=0;counter<cells;counter++)//Using For Loop
{

cell_neighbours[counter][0][0]=cell_status[counter][0]-1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][0][1]=cell_status[counter][1]-1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][1][0]=cell_status[counter][0];//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][1][1]=cell_status[counter][1]-1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][2][0]=cell_status[counter][0]+1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][2][1]=cell_status[counter][1]-1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][3][0]=cell_status[counter][0]-1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][3][1]=cell_status[counter][1];//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][4][0]=cell_status[counter][0]+1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][4][1]=cell_status[counter][1];//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][5][0]=cell_status[counter][0]-1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][5][1]=cell_status[counter][1]+1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][6][0]=cell_status[counter][0];//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][6][1]=cell_status[counter][1]+1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][7][0]=cell_status[counter][0]+1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable
cell_neighbours[counter][7][1]=cell_status[counter][1]+1;//Using Formula of Calculation Neighbour Assigning Literal in a Variable

}
cout<<endl;//Displaying									
}										
int borner()//Declaring Function to calculate newly born cells
{
int counter=0,counter1=0,counter2=0,counter3=0;//Declaring 4-Byte Variables
counter4=0;//Assigning Literal to a Variable
	for (int counter=0;counter<cells-1;counter++)//Using For Loop
	{
		for (int counter1=1;counter1<cells;counter1++)//Using For Loop
		{
			for (int counter2=0;counter2<8;counter2++)//Using For Loop
			{
				for (int counter3=0;counter3<8;counter3++)//Using For Loop
				{
					if ((cell_neighbours[counter][counter2][0]==cell_neighbours[counter1][counter3][0])
					 && (cell_neighbours[counter][counter2][1]==cell_neighbours[counter1][counter3][1]))//Using Conditional Statement
					{ 	if ((counter!=counter1) && (counter<counter1))//Using Conditional Statement
						{
						shared_neighbours[counter4][0]=cell_neighbours[counter][counter2][0];//Assigning Literal to a Variable
						shared_neighbours[counter4][1]=cell_neighbours[counter][counter2][1];//Assigning Literal to a Variable

						counter4++;//Incrementing
						}

					}
				}
			}
		}
	


	} 

int count[counter4];//Declaring

	for (counter=0;counter<counter4;counter++)//Using For Loop
	{
		count[counter]=0;//Assigning Literal to a Variable
	}

	for (counter=0;counter<counter4;counter++)//Using For Loop
	{	
		for (counter1=0;counter1<counter4;counter1++)//Using For Loop
		{
			if ((shared_neighbours[counter][0]==shared_neighbours[counter1][0]) 
			&& (shared_neighbours[counter][1]==shared_neighbours[counter1][1]))//Using Conditional Statement 
			{
				count[counter]++;//Incrementing
		
			}
		}
	}
count_remainers=0;//Assigning Literal to a Variable
	for (counter=0;counter<counter4;counter++)//Using For Loop
	{
		for (counter1=0;counter1<cells;counter1++)//Using For Loop
		{
			if ((count[counter]==1) && (shared_neighbours[counter][0]==cell_status[counter1][0])
			 && (shared_neighbours[counter][1]==cell_status[counter1][1]))//Using Conditional Statement
			{
			temp_remainers[count_remainers][0]=shared_neighbours[counter][0];//Assigning Literal to a Variable
			temp_remainers[count_remainers][1]=shared_neighbours[counter][1];//Assigning Literal to a Variable
			count_remainers++;//Increment
					if ((shared_neighbours[counter][0]>=20) || (shared_neighbours[counter][1]>=20))//Using Conditional Statement
					{
						extend_bottom=1;//Assigning Literal to a Variable
					}
					if ((shared_neighbours[counter][0]<=-1) || (shared_neighbours[counter][1]<=-1))//Using Conditional Statement
					{
						extend_top=1;//Assigning Literal to a Variable
					}
			}
		}

	}

count_borns=0;//Assigning Literal to a Variable
counter2=0;//Assigning Literal to a Variable
	for (counter=0;counter<counter4-1;counter++)//Using For Loop
	{
		for (counter1=counter+1;counter1<counter4;counter1++)//Using For Loop
			{
				if (count[counter]==3)//Using Conditional Statement
				{
					if ((shared_neighbours[counter1][0]==shared_neighbours[counter][0])
					 && (shared_neighbours[counter1][1]==shared_neighbours[counter][1]))//Using Conditional Statement
					{
					shared_neighbours[counter1][0]=0;//Assigning Literal to a Variable
					shared_neighbours[counter1][1]=0;//Assigning Literal to a Variable
					}



				}


			}




	} 

count_borns=0;//Assigning Literal to a Variable
	for (counter=0;counter<counter4;counter++)//Using For Loop
	{
		if ((count[counter]==3) && (shared_neighbours[counter][0]!=0) && (shared_neighbours[counter][1]!=0))//Using Conditional Statement
		{
			temp_borns[count_borns][0]=shared_neighbours[counter][0];//Assigning Literal to a Variable
			temp_borns[count_borns][1]=shared_neighbours[counter][1];//Assigning Literal to a Variable
			count_borns++;//Incrementing
		}
	}
int extra_count=0;//Assigning Literal to a Variable
	for (counter=0;counter<count_borns-1;counter++)//Using For Loop
	{
		for (counter1=counter+1;counter1<count_borns;counter1++)//Using For Loop
		{
			if ((temp_borns[counter][0]==temp_borns[counter1][0])
			 && (temp_borns[counter][1]==temp_borns[counter1][1]))//Using Conditional Statement
			{
				temp_borns[counter][0]=0;//Assigning Literal to a Variable
				temp_borns[counter][1]=0;//Assigning Literal to a Variable
				extra_count++;//Incrementing
			}
		}

	}

counter1=0;//Assigning Literal to a Variable
	for (counter=0;counter<count_borns;counter++)//Using For Loop
	{
	temp_borns[counter1][0]=temp_borns[counter][0];//Assigning Literal to a Variable
	temp_borns[counter1][1]=temp_borns[counter][1];//Assigning Literal to a Variable
		if ((temp_borns[counter][0]!=0) && (temp_borns[counter][1]!=0))//Using Conditional Statement
		{
			counter1++;//Incrementing
		}
	}
count_borns=count_borns-extra_count;//Assigning Literal to a Variable


}
int collector()//Declaring Function for collection of newly born cells and remaining cells
{
int counter=0,counter1=0;//Declaring 4-Byte Variable
	for (counter=0;counter<cells;counter++)//Using For Loop
	{
	cell_status[counter][0]=0;//Assigning Literal to a Variable
	cell_status[counter][1]=0;//Assigning Literal to a Variable
	}
cells=count_remainers+count_borns;//Assigning Literal to a Variable
	for (counter=0;counter<count_remainers;counter++)
	{
	cell_status[counter][0]=temp_remainers[counter][0];//Assigning Literal to a Variable
	cell_status[counter][1]=temp_remainers[counter][1];//Assigning Literal to a Variable
	}
counter1=0;//Assigning Literal to Variable
	for (counter=count_remainers;counter<cells;counter++)
	{
	cell_status[counter][0]=temp_borns[counter1][0];//Assigning Literal to a Variable
	cell_status[counter][1]=temp_borns[counter1][1];//Assigning Literal to a Variable
	counter1++;//Increment

	}

}
int rearranger()//Declaring Function to arrange cells in accending order
{
int counter1=0,counter=0,temporary[2];//Declaring 4-Byte Variable
	for (counter1=0;counter1<=cells-2;counter1++)//Using For Loop
	{
		for (counter=0;counter<=cells-2;counter++)//Using For Loop
		{
			if (cell_status[counter][1]>cell_status[counter+1][1]) 
			{
			temporary[0]=cell_status[counter+1][0];//Assigning Literal to Variable
			temporary[1]=cell_status[counter+1][1];//Assigning Literal to Variable
			cell_status[counter+1][0]=cell_status[counter][0];//Assigning Literal to Variable
			cell_status[counter+1][1]=cell_status[counter][1];//Assigning Literal to Variable
			cell_status[counter][0]=temporary[0];//Assigning Literal to Variable
			cell_status[counter][1]=temporary[1];//Assigning Literal to Variable
			}

		}
	counter=0;//Assigning Literal to Variable
	}
	for (counter1=0;counter1<=cells-2;counter1++)//Using For Loop
	{
		for (counter=0;counter<=cells-2;counter++)//Using For Loop
		{
			if ((cell_status[counter][0]>cell_status[counter+1][0]) && (cell_status[counter][1]<=cell_status[counter+1][1]))//Conditional Statement
			{
			temporary[0]=cell_status[counter+1][0];//Assigning Literal to Variable
			temporary[1]=cell_status[counter+1][1];//Assigning Literal to Variable
			cell_status[counter+1][0]=cell_status[counter][0];//Assigning Literal to Variable
			cell_status[counter+1][1]=cell_status[counter][1];//Assigning Literal to Variable
			cell_status[counter][0]=temporary[0];//Assigning Literal to Variable
			cell_status[counter][1]=temporary[1];//Assigning Literal to Variable
			}
		}
	counter=0;//Assigning Literal to a Variable
	}
	for (counter1=0;counter1<=cells-2;counter1++)//Using For Loop
	{
		for (counter=0;counter<=cells-2;counter++)//Using For Loop
		{
			if (cell_status[counter][1]>cell_status[counter+1][1]) //Using Conditional Statement
			{
			temporary[0]=cell_status[counter+1][0];//Assigning Literal to Variable
			temporary[1]=cell_status[counter+1][1];//Assigning Literal to Variable
			cell_status[counter+1][0]=cell_status[counter][0];//Assigning Literal to Variable
			cell_status[counter+1][1]=cell_status[counter][1];//Assigning Literal to Variable
			cell_status[counter][0]=temporary[0];//Assigning Literal to Variable
			cell_status[counter][1]=temporary[1];//Assigning Literal to Variable
			}

		}
	counter=0;//Assigning Literal to a Variable
	}


}
int greater_lower_decider()//Declaring Function to decide whether a grid will be extend from top or from bottom.
{
int counter=0;//Declaring 4-Byte Variable
	for (counter=0;counter<cells;counter++)//Using For Loop
	{
		if (greater_x<=cell_status[counter][0])//Using Conditional Statement
		{
			greater_x=cell_status[counter][0];//Assigning Literal to a Variable
		}
		if (greater_y<=cell_status[counter][1])//Using Conditional Statement
		{
			greater_y=cell_status[counter][1];//Assigning Literal to a Variable
		}
		if (lesser_x>=cell_status[counter][0])//Using Conditional Statement
		{
			lesser_x=cell_status[counter][0];//Assigning Literal to a Variable
		}
		if (lesser_y>=cell_status[counter][1])//Using Conditional Statement
		{
			lesser_y=cell_status[counter][1];//Assigning Literal to a Variable
		}
		if ((greater_x>=20) || (greater_y>=20))//Using Conditional Statement
		{
			extend_bottom=1;//Assigning Literal to a Variable
		}
		if ((lesser_x<=-1) || (lesser_y<=-1))//Using Conditional Statement
		{
			extend_top=1;//Assigning Literal to a Variable
		}	

	}
}
int data_writer()//Declaring Function to write resultant data of cells to file
{
int counter=0;//Declaring 4-Byte Variable
ofstream of ("output.txt");//Opening File
of<<generations<<endl;//Writing in a File
of<<cells<<endl;//Writing in a file
for (counter=0;counter<cells;counter++)//Counter Loop
{
of<<cell_status[counter][0]<<" "<<cell_status[counter][1]<<endl;//Writing in File
}
of.close();//Closing File
}

int dynamic_maker()//Declaring Function to form a Dynamic Grid Array
{
grid1=new int*[greater_y+2];//Assigning Dynamic Array	
int counter=0;//Declaring 4-Byte Variable
	for (counter=0;counter<greater_y+2;counter++)//Using For Loop
	{
		grid1[counter]=new int[greater_x+2];//Creating Dynamic Array
	}

}
int dynamic_remover()//Declaring Function to delete all dynamic arrays and variables
{
int counter=0;//Declaring 4-Byte Variable
	for (counter=0;counter<greater_y+2;counter++)//Using For Loop
	{
		delete[] grid1[counter];//Deleating Dynamic Array
	}
delete[] grid1;//Deleating Dynamic Array
}







