 // Create a look in direction matrix
 // Pos    -> Position of the camera
 // Angs.x -> direction (alpha)
 // Angs.y -> elevation (beta)
 // Angs.z -> roll (rho)
glm::mat4 LookInDirMat(glm::vec3 Pos, glm::vec3 Angs) {
	 
		glm::mat4 R_x = glm::rotate(glm::mat4(1.0), -Angs.x, glm::vec3(1, 0, 0));
		glm::mat4 R_y = glm::rotate(glm::mat4(1.0), -Angs.y, glm::vec3(0, 1, 0)); 
		glm::mat4 R_z = glm::rotate(glm::mat4(1.0), -Angs.z, glm::vec3(0, 0, 1));
		glm::mat4 T_c = glm::translate(glm::mat4(1.0), Pos);
        glm::mat4 out = R_z * R_x * R_y *T_c ;
	return out;
}

 // Create a look at matrix
 // Pos    -> Position of the camera (c)
 // aim    -> Posizion of the target (a)
 // Roll   -> roll (rho)
glm::mat4 LookAtMat(glm::vec3 Pos, glm::vec3 aim, float Roll) {
	glm::mat4 R_y = glm::rotate(glm::mat4(1.0), Roll, glm::vec3(0, 1, 0));
	glm::mat4 Mv = glm::lookAt(Pos, aim, glm::vec3(0, 1, 0));
	glm::mat4 out = R_y * Mv;
	return out;
}



