# 第 5 课：数组与字符串

## 1. 一维数组 = 一排同类型的格子
    int scores[5] = {98, 85, 77, 90, 66};
    下标：scores[0] ~ scores[4]（从 0 开始！）
    ★ 没有 scores[5]！下标范围 0 ~ 长度-1，越界会出错

## 2. 遍历数组（固定套路）
    for (int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
    }
    ★ 习惯写 i < 长度，不要写 <= （差一错误）

## 3. 求平均分套路
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + scores[i];
    }
    double avg = sum / 5.0;   // 除以 5.0 防止整数除法

## 4. 找最大值套路（擂台法）
    int max = scores[0];              // 先假设第一个最大
    for (int i = 1; i < 5; i++) {
        if (scores[i] > max) {        // 发现更大的
            max = scores[i];          // 换上来
        }
    }

## 5. 字符串 = char 数组
    har name[20c] = "Alice";
    末尾有隐藏的结束符 '\0'
    %s 打印整个字符串
    name[0] 访问第一个字符（下标照样从 0 开始）

## 6. 字符串输入输出（第3个练习用）
    char word[50];
    scanf("%s", word);     // ★ 字符串不用加 &！
    printf("%s", word);
    #include <string.h>    // strlen(word) 求长度
