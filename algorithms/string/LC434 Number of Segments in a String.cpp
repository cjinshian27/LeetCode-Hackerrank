class Solution {
	public:
	    int countSegments(string s) {
		        
			int count = 0;
			int i = 0;

			while (i < s.size()){
				if (s[i] != ' ') ++count;
				while (s[i] != ' ' && i < s.size()) ++i;
				++i;
			}

			return count;
	    }
};