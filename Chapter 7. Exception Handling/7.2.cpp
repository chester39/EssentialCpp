//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ January 12th, 2014
//
 
int *alloc_and_init(string file_name)
{
	ifstream infile(file_name.c_str());
	if (!infile)
		return 0;
	int elem_cnt;
	infile >> elem_cnt;
	if (!infile)
		return 0;
	try {
		int *pi = allocate_array(elem_cnt);
		int elem;
		int index = 0;
		while (infile >> elem && index < elem_cnt)
			pi[index++] = elem;
		sort_array(pi, elem_cnt);
		register_data(pi);
	}
	catch (const noMem &memFail) {
		cerr << "alloc_and_init(): allocate_array failure!" << memFail.what() << endl;
		return 0;
	}
	catch (int &sortFail) {
		cerr << "alloc_and_init(): sort_array failure!" << "thrown integer value: " << sortFail << endl;
		return 0;
	}
	catch (string &registerFail) {
		cerr << "alloc_and_init(): register_data failure!" << "thrown string value: " << registerFail << endl;
		return 0;
	}
	return pi;
}