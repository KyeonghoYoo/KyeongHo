package me.kyeongho;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.data.redis.core.ValueOperations;

public class RedisRunner implements ApplicationRunner {

	@Autowired
	StringRedisTemplate redisTemplate;
	
	
	@Override
	public void run(ApplicationArguments args) throws Exception {
		ValueOperations<String, String> values = redisTemplate.opsForValue();
		
		values.set("kyeongho", "ykh");
		values.set("springboot", "2.0");
		values.set("hello", "world");
	}

}
