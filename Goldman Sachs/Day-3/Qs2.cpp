/*
Question Source : https://www.proelevate.in/dsa-practice/6-companies-30-days
Asked By : goldman sachs
Leetcode : 2526. Find Consecutive Integers from a Data Stream
*/
class DataStream
{
public:
    map<int,int> m;
    queue<int> q;
    int K;
    int temp;
    DataStream(int value, int k)
    {
        K=k;
        temp=value;
    }

    bool consec(int num)
    {
        q.push(num);
        m[num]++;
        if(q.size()>=K){
            if(q.size()>K){
                m[q.front()]--;
                if(m[q.front()]==0){
                    m.erase(q.front());
                }
                q.pop();
            }
            if(m.size()==1 && m[temp]>0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }   
    }
};

/*
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */