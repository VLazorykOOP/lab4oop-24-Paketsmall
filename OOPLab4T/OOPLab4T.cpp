

#include <iostream>
#include <string>
using namespace std;

class VectorFloat {
private:
	float* data;
	int size;
	int codeError;
public:
	VectorFloat()
		:size(1), codeError(0), data(new float[1]){
		data[0] = 0.0;
	}
	VectorFloat(int newSize)
		:size(newSize), codeError(0), data(new float[newSize]) {
		for (int i = 0; i < newSize;++i) {
			data[i] = 0.0;
		}
	}
	VectorFloat(int newSize, float value)
		:size(newSize), codeError(0), data(new float[newSize]) {
		for (int i = 0; i < newSize;++i) {
			data[i] = value;
		}
	}
	~VectorFloat() {
		delete[]data;
	}
	VectorFloat& operator++() {
		for (int i = 0; i < this->size;++i) {
			data[i] += 1.0;
		}
		return *this;
	}
	void operator--() {
		for (int i = 0; i < this->size; ++i) {
			data[i] -= 1.0;
		}
	}
	bool operator!() {
		return this->size == 0;
	}
	VectorFloat& operator-() {
		
		for (int i = 0; i < this->size;++i) {
			data[i] = -this->data[i];
		}
		return *this;
	}
    VectorFloat& operator=(const VectorFloat& rhs) {
        if (this != &rhs) {
            delete[] data;
            this->size = rhs.size;
            data = new float[rhs.size];
            for (int i = 0; i < rhs.size; ++i) {
                this->data[i] = rhs.data[i];
            }
        }
        return *this;
    }
    VectorFloat& operator+=(const VectorFloat& rhs) {
        if (this->size != rhs.size) {
            codeError = 1;
            return *this;
        }
        for (int i = 0; i < size; ++i) {
            this->data[i] += rhs.data[i];
        }
        return *this;
    }
    VectorFloat& operator-=(const VectorFloat& rhs) {
        if (this->size != rhs.size) {
            codeError = 1;
            return *this;
        }
        for (int i = 0; i < size; ++i) {
            this->data[i] -= rhs.data[i];
        }
        return *this;
    }
    VectorFloat& operator/=(const VectorFloat& rhs) {
        if (this->size != rhs.size) {
            codeError = 1;
            return *this;
        }
        for (int i = 0; i < size; ++i) {
            this->data[i] /= rhs.data[i];
        }
        return *this;
    }
    VectorFloat& operator*=(const VectorFloat& rhs) {
        if (this->size != rhs.size) {
            codeError = 1;
            return *this;
        }
        for (int i = 0; i < size; ++i) {
            this->data[i] *= rhs.data[i];
        }
        return *this;
    }

    void operator*(float num) {
        for (int i = 0; i < size; ++i) {
            this->data[i] *= num;
        }
    }
    void operator/(float num) {
        for (int i = 0; i < size; ++i) {
            this->data[i] /= num;
        }
    }

    friend istream& operator>>(istream& os, VectorFloat& v) {
        for (int i = 0; i < v.size; ++i) {
            os >> v.data[i];
        }
        return os;
    }

    friend ostream& operator<<(ostream& os, const VectorFloat& v) {
        for (int i = 0; i < v.size; ++i) {
            os << v.data[i] << " ";
        }
        os << endl;
        return os;
    }
    bool operator!=(const VectorFloat& rhs) const {
        return !(this->size == rhs.size && this->data == rhs.data);
    }
    bool operator==(const VectorFloat& rhs) const {
        return this->size == rhs.size && this->data == rhs.data;
    }
    float& operator[](int index) {
        if (index < 0 || index >= size) {
            codeError = 2;
            return data[size - 1];
        }
        return data[index];
    }

    bool operator>(const VectorFloat& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] > other.data[i]) {
                return false;
            };
        }
        return true;
    }
    bool operator>=(const VectorFloat& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] >= other.data[i]) {
                return false;
            };
        }
        return true;
    }
    bool operator<(const VectorFloat& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] < other.data[i]) {
                return false;
            };
        }
        return true;
    }
    bool operator<=(const VectorFloat& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] <= other.data[i]) {
                return false;
            };
        }
        return true;
    }


};

int main() {

    VectorFloat v1(3, 1.5);
    VectorFloat v2(3, 2.5);  v1 = ++i;
    cout << "v1: " << v1 << std::endl;
    cout << "v2: " << v2 << std::endl;

    VectorFloat v3;
    cout << "v3: " << v3 << std::endl;

    return 0;
}
















#include <iostream>
#include <string>
#include <map>
using namespace std;


class CountriesAndCapitals {
private:
    map<string, string> data;
    int codeError;
public:
    CountriesAndCapitals()
        :codeError{ 0 } {};
    ~CountriesAndCapitals() {};
    void addPair(string& country, string& capital) {
        data[country] = capital;
    }
    string& operator[](string& country) {
        if (data.find(country) != data.end()) {
            return data[country];
        }
        codeError = 1;
        return data.begin()->second;
    }
    string& operator()(string& country) {
        return (*this)[country];
    }
    friend istream& operator>>(istream& is, CountriesAndCapitals& obj) {
        int n;
        std::cout << "Enter the number of pairs: ";
        is >> n;
        string country, capital;
        for (int i = 0; i < n; ++i) {
            std::cout << "Enter country: ";
            is >> country;
            std::cout << "Enter capital: ";
            is >> capital;
            obj.addPair(country, capital);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const CountriesAndCapitals& obj) {
        for (const auto& pair : obj.data) {
            os << "Country: " << pair.first << ", Capital: " << pair.second << std::endl;
        }
        return os;
    }
};

int main() {
    CountriesAndCapitals map;
    cin >> map;
    cout << "Country-Capital pairs:" << endl << map;

    string countryToFind;
    cout << "Enter a country to find its capital: ";
    cin >> countryToFind;
    cout << "Capital of " << countryToFind << ": " << map(countryToFind) << endl;


    return 0;
}















#include <iostream>
#include <string>
#include <map>
using namespace std;

class VectorFload : public error_code {
private:
    float* data;
    int size;
    int codeError;
public:
    VectorFload() : size(1), codeError(0), data(new float[size]) {
        codeError = 0;
        data[0] = 0.0;
    }

    VectorFload(int n) : size(n), codeError(0), data(new float[size]) {
        codeError = 0;
        for (int i = 0; i < size; ++i) {
            data[i] = 0.0;
        }
    }

    VectorFload(int n, float value) : size(n), codeError(0), data(new float[size]) {
        codeError = 0;
        for (int i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    ~VectorFload() {
        delete[] data;
    }
    float& operator[](int index) {
        if (index < 0 || index >= size) {
            codeError = 1;
            return data[size - 1];
        }
        return data[index];
    }

};

class MatrixFload {
private:
    VectorFload* FloatArray;
    int n, size;
    int codeError;
    static int num_matrix;
public:
    MatrixFload() : FloatArray(nullptr), n(0), size(0), codeError(0) {};
    MatrixFload(int size) : n(size), size(size), codeError(0) {
        FloatArray = new VectorFload[size];
        for (int i = 0;i < size; ++i) {
            FloatArray[i] = VectorFload(size);
            FloatArray[i] = 1.0;
        }
        num_matrix++;
    }
    MatrixFload(int n, int m) : n(n), size(m), codeError(0) {
        FloatArray = new VectorFload[n];
        for (int i = 0; i < n;++i) {
            FloatArray[i] = VectorFload(m);
        }
        num_matrix++;
    }

    MatrixFload(int n, int m, float value) : n(n), size(m), codeError(0) {
        FloatArray = new VectorFload[n];
        for (int i = 0; i < n; ++i) {
            FloatArray[i] = VectorFload(m, value);
        }
        num_matrix++;
    }

    int getN() const { return n; }
    int getSize() const { return size; }
    int getCodeError() const { return codeError; }
    static int getNumMatrix() { return num_matrix; }

    MatrixFload& operator++() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size;++j) {
                ++FloatArray[i][j];
            }
        }
        return *this;
    }
    MatrixFload& operator--() {
        for (int i = 0; i < n;++i) {
            for (int j = 0; j < size; ++j) {
                --FloatArray[i][j];
            }
        }
        return *this;
    }

    bool operator!() const {
        return (n == 0 && size == 0);
    }

    MatrixFload operator-() const {
        MatrixFload result(*this);
        for (int i = 0; i < n;++i) {
            for (int j = 0; j < size; ++j) {
                result.FloatArray[i][j] = -result.FloatArray[i][j];
            }
        }
        return result;
    }
    MatrixFload& operator=(const MatrixFload& rhs) {
        if (this != &rhs) {
            delete[] FloatArray;
            n = rhs.n;
            size = rhs.size;
            codeError = rhs.codeError;
            FloatArray = new VectorFload[n];
            for (int i = 0; i < n; ++i) {
                FloatArray[i] = rhs.FloatArray[i];
            }
        }
        return *this;
    }
    MatrixFload operator+(const MatrixFload& rhs) {
        if (n != rhs.n || size != rhs.size) {
            codeError = 1;
            return *this;
        }
        MatrixFload result(n, size);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                result.FloatArray[i][j] = FloatArray[i][j] + rhs.FloatArray[i][j];
            }
        }
        return result;
    }
    template<class T>
    MatrixFload operator+(T scalar) const {
        MatrixFload result(*this);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                result.FloatArray[i][j] += scalar;
            }
        }
        return result;
    }


    MatrixFload operator-(const MatrixFload& rhs) {
        if (n != rhs.n || size != rhs.size) {
            codeError = 1;
            return *this;
        }
        MatrixFload result(n, size);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                result.FloatArray[i][j] = FloatArray[i][j] - rhs.FloatArray[i][j];
            }
        }
        return result;
    }
    template<class T>
    MatrixFload operator-(T scalar) const {
        MatrixFload result(*this);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                result.FloatArray[i][j] -= scalar;
            }
        }
        return result;
    }

    MatrixFload operator*(const MatrixFload& rhs) {
        if (n != rhs.n || size != rhs.size) {
            codeError = 1;
            return *this;
        }
        MatrixFload result(n, size);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                result.FloatArray[i][j] = FloatArray[i][j] * rhs.FloatArray[i][j];
            }
        }
        return result;
    }
    MatrixFload operator/(float scalar) const {
        MatrixFload result(*this);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                result.FloatArray[i][j] /= scalar;
            }
        }
        return result;
    }


    MatrixFload& operator+=(const MatrixFload& rhs) {
        *this = *this + rhs;
        return *this;
    }

    template<class T>
    MatrixFload& operator+=(T scalar) {
        *this = *this + scalar;
        return *this;
    }

    MatrixFload& operator-=(const MatrixFload& rhs) {
        *this = *this - rhs;
        return *this;
    }

    template<class T>
    MatrixFload& operator-=(T scalar) {
        *this = *this - scalar;
        return *this;
    }


    MatrixFload& operator/=(float rhs) {
        *this = *this / rhs;
        return *this;
    }

    template<class T>
    MatrixFload& operator/=(T scalar) {
        *this = *this / scalar;
        return *this;
    }


    MatrixFload& operator*=(const MatrixFload& rhs) {
        *this = *this * rhs;
        return *this;
    }

    template<class T>
    MatrixFload& operator*=(T scalar) {
        *this = *this * scalar;
        return *this;
    }

    bool operator==(const MatrixFload& rhs) {
        if (n != rhs.n || size != rhs.size) {
            codeError = 1;
            return false;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size;++j) {
                if (FloatArray[i][j] != rhs.FloatArray[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!=(const MatrixFload& rhs) {
        if (n != rhs.n || size != rhs.size) {
            codeError = 1;
            return false;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0;j < size; ++j) {
                if (FloatArray[i][j] != rhs.FloatArray[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator>(const MatrixFload& other) {
        if (n != other.n || size != other.size) {
            codeError = 1;
            return false;
        }
        for (int i = 0;i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                if (FloatArray[i][j] <= other.FloatArray[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator>=(const MatrixFload& other) {
        if (n != other.n || size != other.size) {
            codeError = 1;
            return false;
        }
        for (int i = 0;i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                if (FloatArray[i][j] < other.FloatArray[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator<(const MatrixFload& other) {
        if (n != other.n || size != other.size) {
            codeError = 1;
            return false;
        }
        for (int i = 0;i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                if (FloatArray[i][j] >= other.FloatArray[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }


    bool operator<=(const MatrixFload& other) {
        if (n != other.n || size != other.size) {
            codeError = 1;
            return false;
        }
        for (int i = 0;i < n; ++i) {
            for (int j = 0; j < size; ++j) {
                if (FloatArray[i][j] >= other.FloatArray[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    VectorFload& operator[](int index) {
        if (index < 0 || index >= n) {
            codeError = 1;
            return FloatArray[n - 1];
        }
        return FloatArray[index];
    }

    friend istream& operator>>(istream& is, MatrixFload& matrix) {
        for (int i = 0; i < matrix.n;++i) {
            is >> reinterpret_cast<bool&>(matrix.FloatArray[i]);
        }
        return is;
    }

    friend ostream& operator<<(std::ostream& os, const MatrixFload& matrix) {
        for (int i = 0; i < matrix.n;++i) {
            os << matrix.FloatArray[i] << endl;
        }
        return os;
    }

};






