#include <iostream>
#include <cstring>
using namespace std;

void touppercase(char* words){
	for(int i=0; words[i] != '\0'; i++){
		words[i] = toupper(words[i]);
	}
}

class Matrix{
	private:
		char area[24][24];
		
	public:
		Matrix() {
        char temp[24][24] = {
            {"AAFLKHPFSSUFICICLESGNNH"},
            {"SFVREOMRWLRTTSXOQQNAOAO"},
            {"QEIAIFXAEIRFVFYSXIMINJI"},
            {"WSTRLGOCAPBIAFIWIWTUACM"},
            {"FEYAEAISTPCRLUJKOAKCERS"},
            {"RVDAKPNDEEHDEMSNCKKFOAH"},
            {"MRNEDSLCRRIWNRSAAFITMMI"},
            {"YAAECIEAHYMOTAVHRSSTISB"},
            {"RJSEWELCCENNIETOHWSGLSE"},
            {"ATANYYMOIEESNESIOIRELTR"},
            {"UTENEWEBHMYBETNNRAIEBEN"},
            {"RCLKUTEAEQJLSGSHTGDSKOA"},
            {"BHOICATNRRSDDECEHOOLGIT"},
            {"ENSLUARIRSETALOCOHCTOHE"},
            {"FZFUDQJYMADOYIWYGLOVESU"},
            {"TEKALFWONSNAEBMIEJTZNTG"},
            {"ESWPOSJXEUTUYOZUWAKEZHM"},
            {"KZUHBPEZEERFLMSNOWBALLH"},
            {"NSNOWBOARDYTVWYCLEVOHSA"},
            {"ACOCRQLGZIYCHODRAZZILBI"},
            {"LBVKKWANZAAQINWOLPWONSL"},
            {"BFREEZINGRAINSLILGTMELT"},
            {"HQPYLWHFMNFFUFPSWXNUMMV"}
        };

        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 24; j++) {
                area[i][j] = temp[i][j];
            }
        }
    }
    bool find(const char* kata){
    	int len = strlen(kata);
    	
    	//hori kiri-kanan
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j <= 24 - len; j++) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i][j + k] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }

        // hori kanan-kiri
        for (int i = 0; i < 24; i++) {
            for (int j = 23; j >= len - 1; j--) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i][j - k] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }
        
        //ver atas-bawah
        for (int j = 0; j < 24; j++) {
            for (int i = 0; i <= 24 - len; i++) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i + k][j] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }

        //ver bawah-atas
        for (int j = 0; j < 24; j++) {
            for (int i = 23; i >= len - 1; i--) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i - k][j] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }
        
        //diag ataskiri
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 24; j++) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i - k][j - k] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }

        //diag ataskanan
        for (int i = 0; i < 24; i++) {
            for (int j = 0; j <= 24; j++) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i - k][j + k] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }

        //diag bawahkanan
        for (int i = 0; i <= 24; i++) {
            for (int j = 0; j <= 24; j++) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i + k][j + k] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }

        //diag bawah kiri
        for (int i = 0; i <= 24; i++) {
            for (int j = 0; j < 24; j++) {
                bool found = true;
                for (int k = 0; k < len; k++) {
                    if (area[i + k][j - k] != kata[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }

        return false;
        
	}
};

int main(){
	int n;
	cin >> n;

	
	char words[n][24];
	
	Matrix matrix;
	
	for(int i=0; i<n;i++){
		cin.ignore();
		cin.getline(words[i], 25);
		
		touppercase(words[i]);
	}
	
	for(int i=0; i<n; i++){
		if(matrix.find(words[i])){
			cout << "ada" << endl;
		} else{
			cout << "tidak ada" <<endl;
		}
	}
	
	return 0;
}
