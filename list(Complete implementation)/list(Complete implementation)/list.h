namespace lth
{
	template<class T>
	struct __list_node // 节点
	{
		__list_node<T>* _next; // node* _next;
		__list_node<T>* _prev; // node* _prev;
		T _data;

		__list_node(const T& x = T()) //构造函数              节点的构造函数(_list_node(const T&x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator //			typedef	__list_iterator<T,T&,T*> iterator							定义迭代器 类
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> Self;

		node* _node; //也可以 __list_node<T>* _node;                     迭代器指针

		__list_iterator(node* node)         //                         迭代器构造函数(赋指针)
			:_node(node)
		{}

		Ref operator*() // 内置类型         Ref： T&
		{
			return _node->_data;
		}

		Ptr operator->() // 自定义类型     Ptr: T*
		{
			return &_node->_data;
		}


		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		// it1 !=  it2
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T> //类模板  定义list
	class list
	{
		typedef __list_node<T> node;
	public:
		//定义普通iterator迭代器 和const_iterator迭代器
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		const_iterator begin() const //__list_iterator<T, const T&, const T*>
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const //__list_iterator<T, const T&, const T*>
		{
			return const_iterator(_head);
		}

		iterator begin() //_list_iterator<T,T&,T*>
		{
			return iterator(_head->_next);
		}

		iterator end()//_list_iterator<T,T&,T*>
		{
			return iterator(_head);
		}

		// copy(l)
		/* list(const list<T>& l)
		{
		//自己写的
		_head = new node;//可以不要形参？？？ 在这里是什么啊node
		_head->_next =_head;
		_head->_prev =_head;
		const_iterator it = l.begin();
		while(it != l.end())
		{
		push_back(*it);
		++it;
		}
		}*/
		//clear (除头结点全部释放)
		/* void clear()
		{
		iterator it = l.begin();
		while(it != end())
		{
		it = earse(it);
		}
		}
		// l2 = l1
		list <T>&(const list<T>& l)
		{
		clear();
		const_iterator it = l.begin();
		while(it != l.end())
		{
		push_back(*it);
		++it;
		}
		}*/

		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			//const_iterator it = l.begin();
			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		// l2 = l1
		/*list<T>& operator=(const list<T>& l)
		{
		this->clear();

		auto it = l.begin();
		while (it != l.end())
		{
		push_back(*it);
		++it;
		}
		}*/
		// l2 = l1
		list<T>& operator=(list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}

		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		//void push_back(const T& x)
		//{
		//	node* tail = _head->_prev;
		//	node* newnode = new node(x);

		//	// head ... tail newnode 
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			node* cur = pos._node;
			assert(cur != _head);

			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			return iterator(next);
		}

	private:
		node* _head;
	};

	void print_list(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10; // it.operator*() = 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}


	void test_list1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		print_list(l);

		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			if (*it % 2 == 0)
			{
				it = l.erase(it);
			}
			else
			{
				++it;
			}
		}

		print_list(l);
	}

	struct Date
	{
		int _year = 1900;
		int _month = 1;
		int _day = 1;
	};

	void test_list2()
	{
		list<Date> l;
		l.push_back(Date());
		l.push_back(Date());

		//list<Date>::iterator it = l.begin();
		auto it = l.begin();
		while (it != l.end())
		{
			//cout << *it << endl;
			cout << it->_year << "-" << it->_month << "-" << it->_day << endl;
			++it;
		}

		//int* p *p
		//Date* p p->_year;
	}

	void test_list3()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		//print_list(l);

		list<int> copy = l;
		l.push_back(5);

		print_list(copy);
		print_list(l);
	}
}