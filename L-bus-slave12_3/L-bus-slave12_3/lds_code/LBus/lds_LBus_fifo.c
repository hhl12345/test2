#include "lds_LBus_fifo.h"
/*
stLBusTxBuf_t gstLBusTxBuf;
stLBusRxBuf_t gstLBusRxBuf;
*/
/**
  * @brief      Send DALI cmd if there is frame to be sent
  *
  * @param      None
  *
  * @return     None
  */
/*
void LBus_sendScan(void){
  if(gstLBusTxBuf.cCurrentIndex != gstLBusTxBuf.cFinalIndex){
    if(FALSE == dali_bit_getSendReadyFlagStat()){
      gstLBusTxBuf.cCurrentIndex++;
      if(CAN_TX_BUF_LEN_MAX <= gstLBusTxBuf.cCurrentIndex){
        gstLBusTxBuf.cCurrentIndex = 0;
      }
      dali_bit_encode(stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].uiFrame,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].eFrameType,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].eBitLen,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].ePriority,
                      stDaliSendBuf.atDaliSend[stDaliSendBuf.cCurrentSendBufNum].cRepeat);
    }
  }
}
*/

