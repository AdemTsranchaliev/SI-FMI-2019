

void Revert(long& number)
{

	long number2 = 0;
	long numberTemp = number;
	while (numberTemp != 0)
	{
		int num = numberTemp % 10;
		number2 = (number2 * 10) + num;
		numberTemp /= 10;
	}
	number = number2;
}

int GetWord(char str[])
{

	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	if (counter == 0)
	{
		return -1;
	}
	int validationCount = 0;
	for (int i = 0; i < counter; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			validationCount++;
		}
	}
	if (validationCount == counter)
	{
		return -1;
	}

	int max = 0;
	int counter2 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (str[i] != ' '&& str[i] != '\t')
		{
			counter2++;
		}
		else
		{
			if (counter2 > max)
			{
				max = counter2;
			}
			counter2 = 0;
		}

		if (i == counter - 1)
		{
			if (counter2 > max)
			{
				max = counter2;
			}
		}
	}
	counter2 = 0;
	int index = 0;
	for (int i = 0; i < counter; i++)
	{
		if (counter2 == 0)
		{
			index = i;
		}
		if (str[i] != ' ' && str[i] != '\t')
		{
			counter2++;
		}
		else
		{
			if (counter2 == max)
			{
				break;
			}
			counter2 = 0;
		}
	}


	return index;
}


int Find(long N, int n)
{
	if (n <= 0 || n >= 9)
	{
		return -1;
	}
	if (N < 0)
	{
		return -1;
	}
	long temp = N;
	int count = 0;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	if (n > count)
	{
		return -1;
	}
	int* arr = new int[count];
	int* arr2 = new int[count];
	temp = N;
	count = 0;
	while (temp != 0)
	{
		arr[count] = temp % 10;
		temp /= 10;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		arr2[i] = arr[count - 1 - i];
	}
	int max = INT_MIN;
	for (int i = 0; i <= count - n; i++)
	{
		int a = 0;
		for (int j = i; j < n + i; j++)
		{
			a = a * 10 + arr2[j];
		}
		if (max < a)
		{
			max = a;
		}

	}

	return max;
}