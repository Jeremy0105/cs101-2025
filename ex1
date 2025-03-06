#include <stdio.h>

int main() {
    FILE *fp;
    
    // 定義三個陣列
    int a[] = {0, 1, 2};
    char b[] = "ABC"; // 字串包含 '\0' 結尾
    float c[] = {1.1, 1.2, 1.3};

    // 寫入二進位檔案
    fp = fopen("a.bin", "wb");
    if (!fp) {
        printf("無法開啟檔案\n");
        return 1;
    }
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp); // 只寫入 'A', 'B', 'C'
    fwrite(c, sizeof(float), 3, fp);
    fclose(fp);

    // 清空陣列以測試讀取
    int ra[3];
    char rb[3];
    float rc[3];

    // 讀取二進位檔案
    fp = fopen("a.bin", "rb");
    if (!fp) {
        printf("無法開啟檔案\n");
        return 1;
    }
    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 3, fp);
    fread(rc, sizeof(float), 3, fp);
    fclose(fp);

    // 輸出讀取的內容
    printf("整數陣列: %d %d %d\n", ra[0], ra[1], ra[2]);
    printf("字元陣列: %c %c %c\n", rb[0], rb[1], rb[2]);
    printf("浮點數陣列: %.1f %.1f %.1f\n", rc[0], rc[1], rc[2]);

    return 0;
}
