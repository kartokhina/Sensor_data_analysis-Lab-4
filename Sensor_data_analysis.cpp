#include <iostream>

using namespace std;

void inputData(float** data, int d, int h){
    for (int i = 0; i < d; i++){
        cout << "День " << i + 1 << ": ";
        for (int j = 0; j < h; j++) {
            cin >> data[i][j];
        }
        
    }
}
void printData(float** data, int d, int h) {
    cout << "\nВсе данные:" << endl;
    for (int i = 0; i < d; i++) {
        cout << "День " << i + 1 << ": ";
        for (int j = 0; j < h; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
float dayAverage(const float* row, int h){
    float sum = 0.0;
     for (int i = 0; i < h; i++){
        sum += *(row+i);
    }
    return sum / h;
}

float overallAverage(float** data, int d, int h) {
    float t = 0.0;
    for (int i; i < d; i++){
        for (int j; j < h; j++){
            t += data[i][j];
        }
    }
    return t / (d * h);
}

void showHotDays(float** p, int d, int h){
    float overallAvg = overallAverage(p, d, h);
    for (int i; i < d; i++){
        float dayAvg = dayAverage(p[i], h);
        if (dayAvg > overallAvg){
             cout << "День " << i + 1 << " (среднее = " << dayAvg << ")" << endl;
        }

    }
}

int main() {
    cout << "=== Анализ сенсора ===" << endl;
    cout << "Введите количество дней: ";
    int d;
    cin >> d;

    cout << "Введите количество измерений в дне: ";
    int h;
    cin >> h;
    
    float** data = new float* [d];
    for (int i = 0; i < d; i++){
        data[i] = new float[h];
    }
    

  
    inputData(data, d, h);
    printData(data, d,  h);

    float avg = overallAverage(data, d, h);
    cout << "\nОбщая средняя температура: " << avg << endl;

    showHotDays(data, d, h);
    


    for (int i = 0; i < d; i++) {
        delete[] data[i];
    }
    delete[] data;


    return 0;
}