package Stone.BMI;

public class BMI {
    public static void main(String[] args) {
        //BMI 固定公式：体重÷身高²（体重单位：千克，身高单位：米）
        //第一步先定义变量来存取体重和身高
        double Wight = 65;
        double Height = 1.7;
        //第二步定义个变量来存取计算的结果
        double End = Wight / (Height * Height);
        //第三步根据这个计算的结果来进行判断
        if (End < 18.5) {
            System.out.printf("你的 BMI 为：%f，身体状态：消瘦，健康风险：部分增加", End);
        } else if (End < 23.9) {
            System.out.printf("你的 BMI 为：%f，身体状态：正常，健康风险：正常", End);
        } else if (End < 26.9) {
            System.out.printf("你的 BMI 为：%f，身体状态：偏胖，健康风险：增加", End);
        } else if (End < 29.9) {
            System.out.printf("你的 BMI 为：%f，身体状态：肥胖，健康风险：中度增加", End);
        } else {
            System.out.printf("你的 BMI 为：%f，身体状态：严重肥胖，健康风险：严重增加", End);
        }
        ;
        //根据判断的结果来进行格式化输出
    }
}
