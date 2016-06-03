#ifndef NODE_H
#define NODE_H

template <class T>
class NODE{
	protected:
		T m_Data; 	//miembro dato
		
	public:
		NODE<T> *Next; 		//puntero que apunta al siguiente
		NODE(T);
		~NODE();
		void setData(T);
		T getData();

};

#endif // NODE_H