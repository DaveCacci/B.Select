#Unbounded PI controller
class PIController:
    def __init__(self, kp, ki):
        self.kp = kp
        self.ki = ki
        self.integral = 0

    def compute(self, error):
        self.integral += error
        return self.kp * error + self.ki * self.integral