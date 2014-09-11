#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


#define COLCULATE_RESULT 24.0
#define FLOAT_ZERO 0.000001

void show(vector<float> Arr)
{
   for(vector<float>::iterator it = Arr.begin(); it != Arr.end(); it++)
   {
      cout<<" "<<*it;
   }

   cout<<endl;
}

bool f24Game(vector<float> Arr)
{
    //show(Arr);
	if (Arr.size() == 1)
	{
		// 已经计算完4所有的数
		return (Arr.front() == COLCULATE_RESULT) ? true: false;
		
	}
	else
	{
		// 计算剩余的数

		for(int j = 0; j < Arr.size(); j++)
		{
			// 先取一个数，作为第一个计算数
			vector<float> temp  = Arr;
			temp.erase(temp.begin() + j);
                        
            //show(temp);
			float firstNum = Arr[j];

			for (int i = 0; i < temp.size(); i++)
			{
				float SecondNum = temp[i];

				// +
				std::vector<float> AddArr = temp;
				AddArr[i] = firstNum + SecondNum;

				bool result = f24Game(AddArr);

				if(result)
				{
					return true;
				}

				// -
				std::vector<float> subArr = temp;
				subArr[i] = firstNum - SecondNum;

				result = f24Game(subArr);

				if(result)
				{
					return true;
				}

				// *
				std::vector<float> mulitArr = temp;
				mulitArr[i] = firstNum * SecondNum;

				result = f24Game(mulitArr);

				if(result)
				{
					return true;
				}

				// /

				if( SecondNum > FLOAT_ZERO || SecondNum < -FLOAT_ZERO)
				{
					std::vector<float> DivArr = temp;
					DivArr[i] = firstNum / SecondNum;

					result = f24Game(DivArr);

					if(result)
					{
						return true;
					}
				}
			}
		}

        // 无解
		return false;
	}
}

int main()
{
	float TestArr1[] = {1, 5, 5, 5};

	vector<float> Arr(TestArr1, TestArr1+sizeof(TestArr1)/sizeof(TestArr1[0]));
        
    //show(Arr);
	if (f24Game(Arr))
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
	return 0;
}
