#pragma once

#include <vector>

namespace ds {
	template <class T, size_t M, size_t N>
	class Matrix {
	public:
		Matrix() {
			int i = 0;
			for (; i < M; i++) {
				int j = 0;
				for (; j < N; j++) {
					_data[i][j] = T();
				}
			}
		}

		Matrix(T init) {
			int i = 0;
			for (; i < M; i++) {
				int j = 0;
				for (; j < N; j++) {
					_data[i][j] = init;
				}
			}
		}

		inline void display() const {
			int i = 0;
			for (; i < M; i++) {
				int j = 0;
				for (; j < N; j++) {
					std::cout << _data[i][j] << " ";
				}
				printf("\n");
			}
			printf("\n");
		}

		inline void identity(T val = 1) {
			if (_rows == _cols) {
				int i = 0;
				for (; i < _rows; i++) {
					int j = 0;
					for (; j < _cols; j++) {
						if (i == j) {
							_data[i][j] = val;
						}
						else {
							_data[i][j] = T();
						}
					}
				}
			}
		}

		T& operator[](const int& index) {
			return *_data[index];
		}

		T& operator()(const int& r, const int& c) {
			return _data[r][c];
		}

		template <typename T, size_t M, size_t N, size_t NC>
		friend Matrix<T, M, NC> operator*(const Matrix<T, M, N> lhs, const Matrix<T, N, NC> rhs);

	private:
		size_t _rows = M;
		size_t _cols = N;

		T _data[M][N];
	};

	template<typename T, size_t M, size_t N, size_t NC>
	Matrix<T, M, NC> operator*(Matrix<T, M, N> lhs, Matrix<T, N, NC> rhs)
	{
		Matrix<T, M, NC> new_matrix;

		for (size_t w = 0; w < NC; w++) {
			for (size_t i = 0; i < M; i++) {
				T sum = T();
				for (size_t j = 0; j < N; j++) {
					sum += rhs(j, w) * lhs(i, j);
				}
				new_matrix(i, w) = sum;
			}
		}

		return new_matrix;
	}
}
