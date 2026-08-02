class DSU {
public:
    vector<int> parent;
    vector<int> sizes;

    DSU(int n) {
        parent.resize(n);
        sizes.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if(xParent == yParent) return;

        if(sizes[xParent] >= sizes[yParent]) {
            parent[yParent] = xParent;
            sizes[xParent] += sizes[yParent];
        } else {
            parent[xParent] = yParent;
            sizes[yParent] += sizes[xParent];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    // 1. Assign ids to emails
    unordered_map<string,int> emailToId; // convert each unique id into a unique integer
    unordered_map<string,string> emailToName; // assign each email to a owner/name
    int id = 0;
    for(auto &account : accounts) {
        int n = account.size();
        string name = account[0];
        for(int i = 1; i < n; i++) {
            string email = account[i];
            // if email doesnt already exist assign new id
            if(emailToId.find(email) == emailToId.end()) emailToId[email] = id++;
            emailToName[email] = name; // store owner of each id
        }
    }


    // 2. Union emails inside each account
    DSU dsu(id);
    for(auto &account : accounts) {
        int firstMail = emailToId[account[1]], n = account.size(); // take first mail as parent
        for(int i = 2; i < n; i++) dsu.Union(firstMail, emailToId[account[i]]);
    }

    // 3. Group emails by DSU parent
    unordered_map<int, vector<string>> groups; // unordered_map<parentId, childrenIds> groups
    for(auto &emails: emailToId) {
        string email = emails.first; // current email ID
        int emailId = emails.second; /// current integer email ID

        int parent = dsu.find(emailId); // parent of current integer email ID

        groups[parent].push_back(email); // in parent's integer email ID push all its string email IDs
    }

    // 4. Create answer
    vector<vector<string>> ans;
    for(auto &x : groups) {
        vector<string> emails = x.second; // get all emails related to a parent id

        sort(emails.begin(), emails.end()); // sort them in ascending order

        vector<string> temp;
        temp.push_back(emailToName[emails[0]]); // get parent email Id owner and push that name
        for(auto &email : emails) temp.push_back(email); // after name push all the email ids

        ans.push_back(temp); // finally push name + email IDs to ans
    }

    return ans;
    }
};