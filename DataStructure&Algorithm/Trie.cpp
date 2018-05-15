/*lower case letter trie tree */
const int sigma_size = 26;  /*'a' to 'z'*/
struct Trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];          //string's value
	int sz;     // total node
	void clear() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }
	int idx (char c) { return c - 'a'; }
	// insert string s, additional value is v. v must be non-zero. Because 0 stand for non-words node.
	void insert(const char *s ,int v)
	{
		int u = 0, n = strlen(s); // u-- from the root row
		if(!ch[u][c])    //not exist
		{
			memset(ch[sz], 0, sizeof(ch[sz]));
			val[sz] = 0;      // the middle node don't contain info
			ch[u][c] = sz++;  //create node
		}
		u = ch[u][c];             //next node's row
	}
	val[u] = v;                       //attach info to last node

	//find the prefix of string's, it no more than len
	void find_prefixes(const char *s, int len, vector<int>& ans)
	{
		int u = 0;
		for(int i = 0; i < len; i++)
		{
			if(s[i] == '\0') break;
			int c = idx(s[i]);
			if(!ch[u][c])  break;
			u = ch[u][c];
			if(val[u] != 0) ans.push_back( val[u] );
		}
	}
};
