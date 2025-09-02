class PIController:
    def __init__(self, kp, ki, saturation_low=None, saturation_high=None, saturate_integral=True):
        self.kp = kp
        self.ki = ki
        self.saturation_low = saturation_low
        self.saturation_high = saturation_high
        self.saturate_integral = saturate_integral
        self.integral = 0

    def compute(self, error):

        # Integral term
        self.integral += error

        # Apply saturation to the integral term if specified
        if self.saturate_integral:
            if self.saturation_low is not None and self.integral < self.saturation_low:
                self.integral = self.saturation_low
            elif self.saturation_high is not None and self.integral > self.saturation_high:
                self.integral = self.saturation_high

        # Calculate the control signal (output)
        control_signal = self.kp * error + self.ki * self.integral

        # Apply saturation to the control signal
        if self.saturation_low is not None and control_signal < self.saturation_low:
            control_signal = self.saturation_low
        elif self.saturation_high is not None and control_signal > self.saturation_high:
            control_signal = self.saturation_high

        return control_signal