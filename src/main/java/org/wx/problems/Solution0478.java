package org.wx.problems;

import java.util.Random;

/**
 * 该题考察的是概率论，主要考虑均匀性，可以从极坐标出发，但是点落在半径上的概率不是均等的
 * 另外一种简单的思路就是生成一个正方形的，使用拒绝策略排除
 */
public class Solution0478 {
    private Random random;
    private double radius;
    private double x_center;
    private double y_center;

    public Solution0478(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
        this.random = new Random();
    }

    /**
     * 该解法的错误原因是这样生成的随机点不是均匀的
     *
     * @return
     */
    public double[] randPoint() {
        Random random = new Random();
        double randomRadius = random.nextDouble(radius);
        double randomRadian = random.nextDouble(0, 2);
        double x_radius = randomRadius * Math.sin(randomRadian * Math.PI);
        double y_radius = randomRadius * Math.cos(randomRadian * Math.PI);
        double[] res = new double[2];
        res[0] = this.x_center + x_radius;
        res[1] = this.y_center + y_radius;
        return res;
    }

    public double[] randPoint2() {
        double u = random.nextDouble();
        double theta = random.nextDouble() * 2 * Math.PI;
        double r = Math.sqrt(u);
        return new double[]{x_center + r * Math.cos(theta) * this.radius, y_center + r * Math.sin(theta) * this.radius};
    }
}
