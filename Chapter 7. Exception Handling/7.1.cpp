//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ January 12th, 2014
//

	ifstream infile(file_name); //Type do not match. 

	ifstream infile(file_name.c_str());
	if (!infile.is_open()) //Open failed or not.
		return 0;
		
	ifstream infile(file_name.c_str());
	if (!infile.is_open())
		return 0;
	int elem_cnt;
	infile >> elem_cnt;
	if (!infile.is_open()) //Open failed or not.
		return 0;

	ifstream infile(file_name.c_str());
	if (!infile.is_open())
		return 0;
	int elem_cnt;
	infile >> elem_cnt;
	if (!infile.is_open())
		return 0;
	int *pi = allocate_array(elem_cnt);
	if (!pi) //Memory allocation succeed or not.
		return 0;