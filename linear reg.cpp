#include <iostream>
#include <vector>
#include <cmath>

class LinearRegression {
private:
    std::vector<double> x;
    std::vector<double> y;
    double slope;
    double intercept;

public:
    LinearRegression(const std::vector<double>& x_vals, const std::vector<double>& y_vals)
        : x(x_vals), y(y_vals), slope(0), intercept(0) {}

    void train() {
        double x_mean = mean(x);
        double y_mean = mean(y);
        double numerator = 0;
        double denominator = 0;

        for (size_t i = 0; i < x.size(); ++i) {
            numerator += (x[i] - x_mean) * (y[i] - y_mean);
            denominator += (x[i] - x_mean) * (x[i] - x_mean);
        }

        slope = numerator / denominator;
        intercept = y_mean - (slope * x_mean);
    }

    double predict(double x_val) {
        return intercept + slope * x_val;
    }

    double getSlope() const {
        return slope;
    }

    double getIntercept() const {
        return intercept;
    }

private:
    double mean(const std::vector<double>& vals) {
        double sum = 0;
        for (double val : vals) {
            sum += val;
        }
        return sum / vals.size();
    }
};

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};

    LinearRegression lr(x, y);
    lr.train();

    std::cout << "Slope: " << lr.getSlope() << std::endl;
    std::cout << "Intercept: " << lr.getIntercept() << std::endl;

    double test_x = 6;
    std::cout << "Prediction for x = " << test_x << ": " << lr.predict(test_x) << std::endl;

    return 0;
}
