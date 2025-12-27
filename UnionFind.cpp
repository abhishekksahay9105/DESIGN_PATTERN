class UnionFind
{
   private:
       std::vector<int> parent;
       std::vector<int> rank;
   
   public:
       void UnionFind (int n)
       {
           parent.resize (n);
           rank.resize (n, 0);
           for (int i = 0; i < n; ++i)
           {
               parent[i] = i;
           }
       }
   
       int find (int x)
       {
           if (x != parent[x])
           {
               return parent[x] = find (parent[x]);
           }
           return parent[x];
       }
   
       void unionSets (int x, int y)
       {
           int rootX = find (x);
           int rootY = find (y);
   
           if (rootX != rootY)
           {
               if (rank[rootX] < rank[rootY])
               {
                   parent[rootX] = rootY;
               }
               else if (rank[rootX] > rank[rootY])
               {
                   parent[rootY] = rootX;
               }
               else
               {
                   parent[rootY] = rootX;
                   rank[rootX]++;
               }
           }
      }
}