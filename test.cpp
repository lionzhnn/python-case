bool compare(pair<int, int> num1, pair<int, int> num2) {
	return num1.first > num2.first;
}

//zhao dao bian hao wei temp_x de shu suo zai hang hao
int find(vector<int> mei,int temp_x) {
	for (auto i = mei.begin(); i != mei.end(); i++) {
		if (*i == temp_x)
			return i - mei.begin();
	}
	return -1;
}

void meituan_dapeichushou() {
	int a, b, c, d, e, f, g;
	while (cin >> a >> b >> c >> d >> e >> f >> g) {
		vector<pair<int, int>> temp;
		temp.push_back(make_pair(e, 0));
		temp.push_back(make_pair(f, 1));
		temp.push_back(make_pair(g, 2));
		sort(temp.begin(), temp.end(), compare);
		int result = 0,index=0;
		while (d > 0 && index<3) {
			int temp_max = temp[index].second;
			int number;
			switch (temp_max) {
			case 0:
				number = (a < d) ? a : d;
				result += e*number;
				d -= number;
				break;
			case 1:
				number = (b < d) ? b : d;
				result += f*number;
				d -= number;
				break;
			case 2:
				number = (c < d) ? c : d;
				result += g*number;
				d -= number;
				break;
			default:
				break;
			}
			index++;
		}
		cout << result << endl;
	}
  }
  void meituan_jieshu{
	int n, m, q;
	vector<int> mei,tuan;
	vector<int> flag_mei;
	while (cin>>n>>m>>q)
	{
		//shujia
		mei = vector<int>( n,0 );
		flag_mei = vector<int>( n,0 );
		int index = 0;
		while (index < q) {
			index++;
			int temp, temp_x, temp_y,find_col_tuan,find_col_mei;
			cin >> temp;
			switch (temp)
			{
			case 1:
				cin >> temp_x >> temp_y;
				find_col_tuan = find(tuan, temp_x);
				find_col_mei = find(tuan, temp_x);
				if (find_col_tuan != -1 || flag_mei[temp_y - 1] == 1 || (find_col_mei != -1 && flag_mei[find_col_mei] == 1))
					break;
				mei[temp_y-1] = temp_x;
				break;
			case 2:
				cin >> temp_x;
				flag_mei[temp_x - 1] = 1;
				break;
			case 3:
				cin >> temp_x;
				flag_mei[temp_x - 1] = 0;
				break;
			case 4:
				cin >> temp_x;
				find_col_mei = find(mei,temp_x);
				if (find_col_mei != -1 && (flag_mei[find_col_mei]==0)) {
					tuan.push_back(temp_x);
					cout << find_col_mei + 1 << endl;
					flag_mei[find_col_mei] = 2;
				}	
				else
				{
					cout << -1 << endl;
				}
				break;
			case 5:
				cin >> temp_x;
				find_col_tuan = find(tuan,temp_x);
				if (find_col_tuan != -1) {
					tuan.erase(tuan.begin() + find_col_tuan);
				}
				break;
			default :
				break;
			}
		}
	}
  }
  void meituan_EF{
  int n;
	string s;
	while (cin >> n >> s) {
		int E_cout=0, F_cout = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'E')
				E_cout++;
			else
				F_cout++;
			int temp_E = E_cout, temp_F = F_cout;
			for (int j = i; j < n; j++) {
				if (s[i] == 'E')
					temp_E++;
				else
					temp_F++;
				max =( max > (temp_E - temp_F)) ? max : (temp_E - temp_F);
			}
		}
		cout << max << endl;
	}
