class Solution
{
		private:
				map<string, int>	m1;
				map<string, int>	m2;
		public:
				bool isGood ()
				{
						for (auto x : m1)
						{
								if (m2[x.first] != x.second)
										return false;
						}
						return true;
				}
				vector<int> findSubstring(string s, vector<string>& words)
				{
						for (int i = 0; i < words.size(); i++)
						{
								m1[words[i]]++;
						}
						
						std::vector<int> ans;
						int k = words.size();
						
						for (int index = 0; < index < words[0].size(); index)
						{
								std::vector<std::string> vec1;
								for (int i = index; i + words[0].size() < s.size();i += words[0].size())
								{
										vec1.push_back(s.substr(i, words[0].size()));
								}

								
								int j = 0;
								while (j < vec1.size())
								{
										m2[vec1[j]]++;
										if (j < k-1)
										{
												continue;
										}
										else
										{

												if (isGood())
												{
														ans.push_back(index+j*words[0].size());
												}
												m2[vec1[j-(k-1)]]--;
										}
								}
						}
				}
};
