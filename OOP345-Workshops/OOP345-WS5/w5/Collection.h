

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name{};
		T* m_arr{};
		size_t m_arraySize{};
		void (*observer)(const Collection<T>&, const T&) {
			nullptr
		};

	public:
		Collection(std::string name) {
			m_name = name;
		}
		Collection(const Collection& source) = delete;
		Collection& operator=(const Collection& source) = delete;
		~Collection() {
			delete[] m_arr;
			m_arr = nullptr;
		};
		const std::string& name() const {
			return m_name;
		};
		size_t size() const {
			return m_arraySize;
		};
		void setObserver(void (*observer)(const Collection<T>&, const T& item)) {
			this->observer = observer;
		};
		Collection<T>& operator+=(const T& item) {
			bool flag = false;
			for (size_t i = 0u; i < m_arraySize; i++) {
				if (item.title() == m_arr[i].title())
					flag = true;
			}
			if (!flag) {
				T* temp = new T[m_arraySize + 1];
				for (size_t i = 0u; i < m_arraySize; i++) {
					temp[i] = m_arr[i];
				}
				temp[m_arraySize] = item;
				m_arraySize++;

				delete[] m_arr;
				m_arr = nullptr;

				m_arr = new T[m_arraySize];
				for (size_t i = 0u; i < m_arraySize; i++) {
					m_arr[i] = temp[i];
				}
				delete[] temp;
				temp = nullptr;

				if (observer != nullptr)
					observer((*this), item);
			}
			return *this;
		};
		T& operator[](size_t idx) const {
			std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
			if (idx >= size())
				throw std::out_of_range(err);

			else {
				return m_arr[idx];
			}
		};

		T* operator[](std::string title) const {
			bool found = false;
			T* ret = nullptr;
			for (size_t i = 0u; i < m_arraySize && !found; i++) {
				if (title == m_arr[i].title()) {
					ret = &m_arr[i];
					found = true;
				}
			}
			return ret;
		};

		friend std::ostream& operator<<(std::ostream& os, const Collection& obj) {
			for (size_t i = 0u; i < obj.size(); i++) {
				os << obj[i];
			}
			return os;
		}
	};
}

#endif //!SDDS_COLLECTION_H
