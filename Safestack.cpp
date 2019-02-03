template <typename T>
class SafeStack{
private:
std::stack<t> data;
std::mutex mut;
public:

Safestack(){};
Safestack(Safestack & other){
std::lock_guard<std::mutex>lock(other.m);
data = other.data;
}
Safestack& operator =(Safestack & other) = delete;
void Pop(){
std::lock_guard<std::mutex> lock(m);
	if (data.empty()) throw std::invalid_argument("error");
	value = std::move(data.top());
data.pop();
}
void push(t new_value)
{
	std::lock_guard<std::mutex>lock(m);
	data.push(std::move(new_value)); 
}
bool empty()const
{
	std::lock_guard<std::mutex> lock(m);
	return data.empty();
}
};
