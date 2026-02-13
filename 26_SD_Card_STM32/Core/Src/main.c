/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int __io_putchar(int ch);
void SD_Card_Test(void);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_SPI1_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */
  SD_Card_Test();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 64;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV4;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : SPI1_CS_Pin */
  GPIO_InitStruct.Pin = SPI1_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI1_CS_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void SD_Card_Test(void)
{
	printf("Start FATFS System\n");
    FATFS FatFs;        // FAT file system object (required by FatFs)
    FIL Fil;            // File object (used to open/read/write files)
    FRESULT FR_Status;  // Stores return status of FatFs functions
    FATFS *FS_Ptr;      // Pointer to file system information
    UINT RWC, WWC;      // RWC = Read byte count, WWC = Written byte count
    DWORD FreeClusters; // Stores number of free clusters in SD card
    uint32_t TotalSize, FreeSpace; // SD card size information
    char RW_Buffer[200]; // Buffer used for both read and write operations

    //------------------[ STEP 1: Mount the SD Card ]--------------------
    // This step makes the SD card ready to use with FatFs
    FR_Status = f_mount(&FatFs, "", 1);
    if (FR_Status != FR_OK)
    {
        // If mounting fails, print error and exit function
        printf("[ERROR] SD Card mount failed! Code = %d\r\n", FR_Status);
        return;
    }

    // SD card mounted successfully
    printf("[INFO] SD Card mounted successfully\r\n\n");

    //------------------[ STEP 2: Get SD Card Size & Free Space ]--------------------
    // Get free cluster count and file system information
    f_getfree("", &FreeClusters, &FS_Ptr);

    // Calculate total size and free space in Bytes
    // csize = cluster size, each sector = 512 bytes
    TotalSize = (FS_Ptr->n_fatent - 2) * FS_Ptr->csize * 512;
    FreeSpace = FreeClusters * FS_Ptr->csize * 512;

    // Print SD card memory details on serial terminal
    printf("[INFO] SD Card Total Size : %lu Bytes\r\n", TotalSize);
    printf("[INFO] SD Card Free Space : %lu Bytes\r\n\n", FreeSpace);

    //------------------[ STEP 3: Create File and Write Data ]--------------------
    // Create a new file or overwrite if it already exists
    FR_Status = f_open(&Fil,
                       "STM_FILE.txt",
                       FA_WRITE | FA_READ | FA_CREATE_ALWAYS);

    if (FR_Status != FR_OK)
    {
        // File creation/open failed
        printf("[ERROR] File create/open failed! Code = %d\r\n", FR_Status);
        return;
    }

    // File created successfully
    printf("[SD] File created: STM_FILE.txt\r\n");

    // Prepare data to be written into the SD card file
    strcpy(RW_Buffer, "[SD] Hello from STM32! Data written using f_write()\r\n");

    // Write data to the file
    FR_Status = f_write(&Fil, RW_Buffer, strlen(RW_Buffer), &WWC);
    if (FR_Status != FR_OK || WWC == 0)
    {
        // Writing failed
        printf("[ERROR] SD file write failed\r\n");
        f_close(&Fil);
        return;
    }

    // Print number of bytes written
    printf("[INFO] Written string to SD card: %s\r\n", RW_Buffer);
    printf("[INFO] Written %d bytes to SD card\r\n", WWC);

    // Close the file after writing
    f_close(&Fil);

    //------------------[ STEP 4: Read File Content ]--------------------
    // Open the same file in read mode
    FR_Status = f_open(&Fil, "STM_FILE.txt", FA_READ);
    if (FR_Status != FR_OK)
    {
        printf("[ERROR] File open for read failed\r\n");
        return;
    }

    // Clear buffer before reading data
    memset(RW_Buffer, 0, sizeof(RW_Buffer));

    // Move file pointer to the beginning of the file
    f_lseek(&Fil, 0);

    // Read data from SD card file into buffer
    FR_Status = f_read(&Fil, RW_Buffer, sizeof(RW_Buffer) - 1, &RWC);
    if (FR_Status == FR_OK)
    {
        // Add null character to make it a valid string
        RW_Buffer[RWC] = '\0';

        // Print file content on serial terminal
        printf("[SD] File content read from SD card:\r\n%s\r\n", RW_Buffer);
    }

    // Close file after reading
    f_close(&Fil);

    //------------------[ STEP 5: Append New Data to File ]--------------------
    // Open existing file in write mode (for updating)
    FR_Status = f_open(&Fil,
                       "STM_FILE.txt",
                       FA_OPEN_EXISTING | FA_WRITE);
    if (FR_Status != FR_OK)
    {
        printf("[ERROR] File open for update failed\r\n");
        return;
    }

    // Move file pointer to the end of the file
    // This ensures new data is appended, not overwritten
    f_lseek(&Fil, f_size(&Fil));

    // New data to be appended at the end of file
    strcpy(RW_Buffer,
           "[SD] This line was appended later\r\n");

    // Write appended data
    f_write(&Fil, RW_Buffer, strlen(RW_Buffer), &WWC);
    printf("[SD] Appended new data to file\r\n");

    // Close file after updating
    f_close(&Fil);

    //------------------[ STEP 6: Read File After Update ]--------------------
    // Open file again to verify updated content
    FR_Status = f_open(&Fil, "STM_FILE.txt", FA_READ);
    if (FR_Status == FR_OK)
    {
        memset(RW_Buffer, 0, sizeof(RW_Buffer));

        // Read entire file content
        f_read(&Fil, RW_Buffer, sizeof(RW_Buffer) - 1, &RWC);
        RW_Buffer[RWC] = '\0';

        // Print updated file content
        printf("[SD] File content after update:\r\n%s\r\n", RW_Buffer);

        f_close(&Fil);
    }

    //------------------[ STEP 7: Unmount the SD Card ]--------------------
    // Properly unmount the SD card to avoid data corruption
    FR_Status = f_mount(NULL, "", 0);
    if (FR_Status != FR_OK)
        printf("[ERROR] SD Card unmount failed! Code = %d\r\n", FR_Status);
    else
        printf("[INFO] SD Card unmounted safely\r\n");
}



int __io_putchar(int ch)
{
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
