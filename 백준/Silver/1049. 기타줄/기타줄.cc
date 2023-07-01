#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int minPackage = 987654321, minPiece = 987654321;

	while (M--) {
		int package, piece;
		cin >> package >> piece;

		minPackage = min(minPackage, package);
		minPiece = min(minPiece, piece);
	}

	int temp1 = (N / 6 + 1) * minPackage;
	int temp2 = min((N / 6 * minPackage + N % 6 * minPiece), N * minPiece);

	cout << min(temp1, temp2) << "\n";
}