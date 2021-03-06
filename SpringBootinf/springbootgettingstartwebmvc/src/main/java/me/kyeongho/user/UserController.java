package me.kyeongho.user;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class UserController {

	@CrossOrigin(origins = "http://localhost:18080")
	@GetMapping("/hello")
	public String hello() {
		return "hello";
	}
	
	@PostMapping("/users/create")
	public User create(@RequestBody User user) {
		return user;
	}
}
