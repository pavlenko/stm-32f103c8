#ifndef PCD8544_H
#define PCD8544_H

#include <stdint.h>

enum PCD8544_DC {
    PCD8544_DC_COMMAND,
    PCD8544_DC_DATA
};

typedef enum PCD8544_DisplayMode_t {
    PCD8544_DISPLAY_MODE_ALL_WHITE = 0,
    PCD8544_DISPLAY_MODE_ALL_BLACK = 1,
    PCD8544_DISPLAY_MODE_NORMAL    = 4,
    PCD8544_DISPLAY_MODE_INVERTED  = 5,
} PCD8544_DisplayMode_t;

class PCD8544 {
private:
    bool _powerDown            = false;
    bool _extendedInstruction  = false;

    void (* _setMode) (uint8_t);
    void (* _setData) (uint8_t);

    void _setFunctionSet();
    void _setPowerDown(bool enabled);
    void _setExtendedInstruction(bool enabled);
    void _setOperationVoltage(uint8_t vop);
    void _setTemperatureCoefficient(uint8_t tc);
    void _setBias(uint8_t bias);
    void _setDisplayMode(PCD8544_DisplayMode_t mode);
public:
    /**
     * Instantiate driver with specific interface adapter functions
     *
     * @param setMode
     * @param setData
     */
    PCD8544(void (* setMode) (uint8_t), void (* setData) (uint8_t));

    void initialize();

    /**
     * Enable/disable power down mode
     *
     * @param enabled
     */
    void setPowerDown(bool enabled);

    /**
     * Set operation voltage (contrast)
     *
     * @param vop
     */
    void setOperationVoltage(uint8_t vop);

    /**
     * Set temperature coefficient
     *
     * @param tc
     */
    void setTemperatureCoefficient(uint8_t tc);

    /**
     * Set bias
     *
     * @param bias
     */
    void setBias(uint8_t bias);

    /**
     * Set display mode
     *
     * @param mode
     */
    void setDisplayMode(PCD8544_DisplayMode_t mode);

    /**
     * Select display column (0...83)
     *
     * @param col
     */
    void setCol(uint8_t col);

    /**
     * Select display row (0...5)
     *
     * @param row
     */
    void setRow(uint8_t row);
};

#endif //PCD8544_H
