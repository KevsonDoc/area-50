import { Controller } from '@nestjs/common';
import { MessagePattern, Payload } from '@nestjs/microservices';
import { DHT11SensorDto } from './dto/dht11-sensor.dto';
import { MqttService } from './mqtt.service';

@Controller()
export class MqttController {
  constructor(private readonly mqttService: MqttService) {}

  @MessagePattern('sensor')
  create(@Payload() data: DHT11SensorDto) {
    return this.mqttService.insert(data);
  }
}
