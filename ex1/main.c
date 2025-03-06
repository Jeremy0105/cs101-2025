#include <stdio.h>

int main() {
    FILE *fp;
    
    // 定義三個陣列
    int a[] = {0, 1, 2};
    char b[] = {'A', 'B', 'C'}; // 手動指定字元，避免額外的 '\0'
    float c[] = {1.1, 1.2, 1.3};

    // 寫入二進位檔案
    fp = fopen("a.bin", "wb+");  // 使用 "wb+" 允許讀寫
    if (!fp) {
        printf("無法開啟檔案\n");
        return 1;
    }
    fwrite(a, sizeof(a), 1, fp);  // 寫入整個陣列
    fwrite(b, sizeof(b), 1, fp);  
    fwrite(c, sizeof(c), 1, fp);

    // 移動檔案指標回到開頭
    fseek(fp, 0, SEEK_SET);

    // 清空陣列以測試讀取
    int ra[3];
    char rb[3];
    float rc[3];

    // 讀取二進位檔案
    fread(ra, sizeof(ra), 1, fp);
    fread(rb, sizeof(rb), 1, fp);
    fread(rc, sizeof(rc), 1, fp);
    
    fclose(fp);

    // 輸出讀取的內容
    printf("整數陣列: %d %d %d\n", ra[0], ra[1], ra[2]);
    printf("字元陣列: %c %c %c\n", rb[0], rb[1], rb[2]);
    printf("浮點數陣列: %.1f %.1f %.1f\n", rc[0], rc[1], rc[2]);

    return 0;
}
