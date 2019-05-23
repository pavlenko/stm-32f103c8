#include "PCD8544.h"

PCD8544::PCD8544(void (* reset) (), void (* setMode) (uint8_t), void (* setData) (uint8_t)): _reset(reset), _setMode(setMode), _setData(setData)
{}

void PCD8544::_setFunctionSet()
{
    this->_setData(0x20 | (this->_powerDown << 2) | this->_extendedInstruction);
}

void PCD8544::_setPowerDown(bool enabled)
{
    this->_powerDown = enabled;
}

void PCD8544::_setExtendedInstruction(bool enabled)
{
    this->_extendedInstruction = enabled;
}

void PCD8544::_setOperationVoltage(uint8_t vop)
{
    this->_setData(0x80u | (0x7Fu & vop));
}

void PCD8544::_setTemperatureCoefficient(uint8_t tc)
{
    if (tc > 3) {
        tc = 3;
    }

    this->_setData(0x04u | tc);
}

void PCD8544::_setBias(uint8_t bias)
{
    if (bias > 7) {
        bias = 7;
    }

    this->_setData(0x10u | bias);
}

void PCD8544::_setDisplayMode(PCD8544_DisplayMode_t mode)
{
    this->_setData(0x08u | mode);
}

void PCD8544::initialize()
{
    this->_reset();
    this->_setMode(PCD8544_DC_COMMAND);

    this->_setExtendedInstruction(true);
    this->_setFunctionSet();

    this->_setOperationVoltage(0x40);
    this->_setTemperatureCoefficient(2);
    this->_setBias(4);

    this->_setExtendedInstruction(false);
    this->_setFunctionSet();

    this->_setDisplayMode(PCD8544_DISPLAY_MODE_NORMAL);
}

void PCD8544::setPowerDown(bool enabled)
{
    this->_setMode(PCD8544_DC_COMMAND);
    this->_setPowerDown(enabled);
    this->_setFunctionSet();
}


void PCD8544::setOperationVoltage(uint8_t vop)
{
    this->_setMode(PCD8544_DC_COMMAND);

    this->_setExtendedInstruction(true);
    this->_setFunctionSet();

    this->_setOperationVoltage(vop);
}

void PCD8544::setTemperatureCoefficient(uint8_t tc)
{
    this->_setMode(PCD8544_DC_COMMAND);

    this->_setExtendedInstruction(true);
    this->_setFunctionSet();

    this->_setTemperatureCoefficient(tc);
}

void PCD8544::setBias(uint8_t bias)
{
    this->_setMode(PCD8544_DC_COMMAND);

    this->_setExtendedInstruction(true);
    this->_setFunctionSet();

    this->_setBias(bias);
}

void PCD8544::setDisplayMode(PCD8544_DisplayMode_t mode)
{
    this->_setMode(PCD8544_DC_COMMAND);

    this->_setExtendedInstruction(false);
    this->_setFunctionSet();

    this->_setDisplayMode(mode);
}

void PCD8544::setCol(uint8_t col)
{
    this->_setMode(PCD8544_DC_COMMAND);
    this->_setData(0x80 | (0x07 & col));
}

void PCD8544::setRow(uint8_t row)
{
    this->_setMode(PCD8544_DC_COMMAND);
    this->_setData(0x40 | (0x3F & row));
}

void PCD8544::setX(uint8_t x)
{
    this->_setMode(PCD8544_DC_COMMAND);
    this->_setData(0x80U | (0x07U & x));
}

void PCD8544::setY(uint8_t y)
{
    this->_setMode(PCD8544_DC_COMMAND);
    this->_setData(0x40U | (0x3FU & y));
}

void PCD8544::setXY(uint8_t x, uint8_t y)
{
    this->_setMode(PCD8544_DC_COMMAND);
    this->_setData(0x80U | (0x07U & x));
    this->_setData(0x40U | (0x3FU & y));
}

void PCD8544::setMode(uint8_t mode)
{
    this->_setMode(mode);
}

void PCD8544::setData(uint8_t data)
{
    this->_setData(data);
}

