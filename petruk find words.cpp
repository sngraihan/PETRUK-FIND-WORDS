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
                    if (area[i][j - k] != len[k]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return true;
                }
            }
        }
	}
};

int main(){
	int n;
	cin >> n;
	char words[n][24];
	
	Matrix matrix;
	
	for(int i=0; i<n;i++){
		cin.getline(words[i], 25);
		touppercase(words[i]);
	}
	
	
	return 0;
}
