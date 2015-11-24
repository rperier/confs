struct reset_control *reset_control_get(
    struct device *dev, const char *id);

struct reset_control *devm_reset_control_get(
    struct device *dev, const char *id);

int device_reset_optional(struct device *dev);
